import random
from os.path import join
import imageio.v2 as imageio
import numpy as np
from matplotlib import pyplot as plt

class Maze(object):
    valid_actions = ['u', 'r', 'd', 'l']  # 机器人动作，包含向上，向右，向下，向左
    direction_bit_map = {'u': 1, 'r': 2, 'd': 4, 'l': 8}  # 设置位图
    move_map = {'u': (-1, 0), 'r': (0, +1), 'd': (+1, 0), 'l': (0, -1)}  # 记录移动地图
    robot_img = {d: imageio.imread(join("images/", "robot-" + d + ".jpg")) for d in valid_actions}  # 读入图片

    def __init__(self, maze_size=(6, 6), trap_num=3):
        self.raw_maze_img = None  # 记录此时迷宫图片
        self.traps = None  # 记录陷阱
        self.destination = None  # 记录目标地点
        self.maze_data = None  # 记录迷宫数据
        self.reward = None  # 记录奖惩
        self.robot = None  # 记录机器人，位置和朝向
        self.generate_maze(maze_size[0] * 2 + 1, maze_size[1] * 2 + 1)  # 创建迷宫
        self.height, self.width = maze_size  # 设置宽高
        self.default_robot_loc = {
            'loc': (1, self.width - 2),
            'dir': 'd',
        }  # 默认机器人位置，行进方向
        self.set_destination()  # 设置目标地点
        self.generate_trap(trap_num=trap_num)  # 制造陷阱
        self.draw_raw_maze_img()  # 展示出图片
        self.place_robot()  # 放置机器人
        self.set_reward()  # 设置奖惩

    # 此处生成随机的迷宫
    def generate_maze(self, height, width, complexity=.25, density=.25):
        # 调整形状大小为奇数
        shape = ((height // 2) * 2 + 1, (width // 2) * 2 + 1)
        # 调整复杂度
        complexity = int(complexity * (5 * (shape[0] + shape[1])))
        # 调整密集程度
        density = int(density * ((shape[0] // 2) * (shape[1] // 2)))
        # 创建迷宫
        amap = np.zeros(shape, dtype=bool)
        # 填充边界
        amap[0, :] = amap[-1, :] = 1
        amap[:, 0] = amap[:, -1] = 1
        # 制作出通道
        for i in range(density):
            x, y = random.randint(0, shape[1] // 2) * 2, random.randint(0, shape[0] // 2) * 2
            amap[y, x] = 1
            for j in range(complexity):
                neighbours = []
                if x > 1:
                    neighbours.append((y, x - 2))
                if x < shape[1] - 2:
                    neighbours.append((y, x + 2))
                if y > 1:
                    neighbours.append((y - 2, x))
                if y < shape[0] - 2:
                    neighbours.append((y + 2, x))
                if len(neighbours):
                    y_, x_ = neighbours[random.randint(0, len(neighbours) - 1)]
                    if amap[y_, x_] == 0:
                        amap[y_, x_] = 1
                        amap[y_ + (y - y_) // 2, x_ + (x - x_) // 2] = 1
                        x, y = x_, y_
        row, col = amap.shape

        # 转换迷宫格式以供记录
        maze_data = np.zeros(((row - 3) // 2 + 1, (col - 3) // 2 + 1), dtype=np.uint8)
        for i in range(0, row - 2, 2):
            for j in range(0, col - 2, 2):
                maze_data[i // 2, j // 2] = sum([1, 2, 4, 8][i] * ~block for i, block in enumerate(np.ravel(amap[i:i + 3, j:j + 3], order='F')[[3, 7, 5, 1]]))

        self.maze_data = maze_data

    def set_destination(self, destination_coord=None):
        # 设置目地点坐标，默认处在中心位置
        if not destination_coord:
            destination_coord = (self.height // 2, self.width // 2)
        self.destination = destination_coord

    def generate_trap(self, trap_num):
        # 随机制造陷阱
        if trap_num > self.width * self.height * 0.1:
            raise ValueError('陷阱数太多')

        avoid_location = int(self.default_robot_loc['loc'][0] * self.width + self.default_robot_loc['loc'][1])
        destination = int(self.destination[0] * self.width + self.destination[1])
        valid_range = list(range(1, avoid_location)) + list(range(avoid_location + 1, destination)) + list(range(destination + 1, int((self.width - 1) * (self.height - 1))))
        trap_list = random.sample(valid_range, trap_num)
        self.traps = [(ele // self.width, ele % self.width) for ele in trap_list]

    def draw_raw_maze_img(self):
        # 加载图像
        grid_images = []
        for i in range(16):
            grid_images.append(imageio.imread(join("images/", str(i) + ".jpg")))
        maze = np.vstack((np.hstack((grid_images[i] for i in row)) for row in self.maze_data))

        # 添加陷阱和目标位置的图片
        trap_img = imageio.imread(join("images", "trap.jpg"))
        destination_img = imageio.imread(join("images", "destination.jpg"))
        grid_size = 100  # 设置默认的大小
        for (row, col) in self.traps:
            maze[row * grid_size:(row + 1) * grid_size, col * grid_size:(col + 1) * grid_size, :] += trap_img
        row, col = self.destination
        maze[row * grid_size:(row + 1) * grid_size, col * grid_size:(col + 1) * grid_size, :] += destination_img

        self.raw_maze_img = maze

    def get_raw_maze_img(self):
        # 获取迷宫图片，提供调用
        return self.raw_maze_img.copy()

    # 116-132行代码为单独展示迷宫图片部分
    def draw_current_maze(self):
        # 获取迷宫图片并添加进机器人图片
        grid_size = 100  # 默认大小
        row, col = self.robot['loc']
        current_maze_img = self.raw_maze_img.copy()
        current_maze_img[row * grid_size:(row + 1) * grid_size, col * grid_size:(col + 1) * grid_size, :] += self.robot_img[self.robot['dir']]
        return current_maze_img

    def __repr__(self):
        # 展示生成好的迷宫
        plt.figure(figsize=(self.height, self.width))
        plt.imshow(self.draw_current_maze())
        plt.axis('off')
        plt.show()
        return 'Maze of size (%d, %d)' % (self.height, self.width)

    def is_permissible(self, location, direction):
        # 判断接下来的一次行动是否会撞到墙壁
        return (self.maze_data[location] & self.direction_bit_map[direction]) != 0

    def place_robot(self):
        # 将机器人放置在迷宫中
        self.robot = self.default_robot_loc.copy()

    def set_reward(self):
        # 对于不同的行为设置奖惩
        self.reward = {
            "hit_wall": -0.5,
            "destination": 50.,
            "trap": -1.0,
            "default": -0.2,
        }

    def move_robot(self, direction):
        # 根据不确定行为移动机器人，返回新位置和移动的奖励
        if direction not in self.valid_actions:
            raise ValueError("Invalid Actions")

        if self.is_permissible(self.robot['loc'], direction):
            self.robot['loc'] = tuple((i + di for i, di in zip(self.robot['loc'], self.move_map[direction])))
            self.robot['dir'] = direction
            if self.robot['loc'] == self.destination:
                reward = self.reward['destination']
            elif self.robot['loc'] in self.traps:
                reward = self.reward['trap']
            else:
                reward = self.reward['default']
        else:
            self.robot['dir'] = direction
            reward = self.reward['hit_wall']
        return reward

    def sense_robot(self):
        # 调用后返回机器人位置
        return self.robot['loc']

    def reset_robot(self):
        # 重置机器人的位置和行进方向
        self.robot = self.default_robot_loc.copy()
