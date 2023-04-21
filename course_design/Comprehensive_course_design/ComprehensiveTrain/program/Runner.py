import numpy as np
import imageio.v2 as imageio

from multiprocessing import cpu_count
from multiprocessing.dummy import Pool

import tqdm
from os.path import join
from copy import deepcopy

from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw
import cv2

import matplotlib.pyplot as plt
#训练机器人，实现整个训练过程及可视化。在当前文件夹中生成一个名为 filename 的视频，记录了整个训练的过程。
class Runner(object):
    valid_actions = ['u', 'r', 'd', 'l'] # 规定动作：上，右，下，左
    robot_img = {d:imageio.imread(join("images/","robot-"+d+".jpg")) for d in valid_actions}
    logo_img = imageio.imread("images/logo.jpg")
    arrow_img = {d:imageio.imread(join("images/","arrow-"+d+".jpg")) for d in valid_actions}
    header_font = ImageFont.truetype("abel-regular.ttf", 55)
    font = ImageFont.truetype("abel-regular.ttf", 30)

    def __init__(self, robot, maze):
        self.maze = maze#迷宫
        self.robot = robot#机器人


    #训练（训练次数，每次训练机器人最多移动的步数，显示方向
    def run_training(self, training_epoch, training_per_epoch=300, display_direction=False):
        training_per_epoch = int(self.maze.height * self.maze.height * 5.0)
        #训练记录
        self.train_robot_record = {}  #type:dict
        #训练机器的状态记录，成功，奖励值，次数，这些参数
        self.train_robot_statics = {
            'success': [],
            'reward': [],
            'times': [],
        }#type:dict
        self.display_direction = display_direction
        #训练之前的记录
        def train_logger_before_act(e, i):

            self.train_robot_record[(e,i)] = {}
            self.train_robot_record[(e,i)]['id'] = (e,i)
            self.train_robot_record[(e,i)]['success'] = False

            self.train_robot_record[(e,i)]['state'] = self.robot.sense_state()
            self.train_robot_record[(e,i)]['qtable'] = self.robot.Qtable[self.robot.sense_state()].copy()

            self.train_robot_record[(e,i)]['epsilon'] = self.robot.epsilon
            self.train_robot_record[(e,i)]['alpha'] = self.robot.alpha
            self.train_robot_record[(e,i)]['gamma'] = self.robot.gamma

            self.train_robot_record[(e,i)]['maze_loc'] = self.maze.robot.copy()

            if self.display_direction:
                self.train_robot_record[(e,i)]['Qtable'] = deepcopy(self.robot.Qtable)

        def train_logger_after_act(e, i, action, reward):

            self.train_robot_record[(e,i)]['action'] = action
            self.train_robot_record[(e,i)]['reward'] = reward

        for e in range(training_epoch):
            accumulated_reward = 0
            run_time = 0
            for i in range(training_per_epoch):
                train_logger_before_act(e, i)
                action, reward = self.robot.update()
                train_logger_after_act(e, i, action, reward)
                run_time += 1
                accumulated_reward += reward
                if self.maze.robot['loc'] == self.maze.destination:
                    i+=1
                    train_logger_before_act(e,i)
                    self.train_robot_record[(e,i)]['success'] = True
                    break
            if self.maze.robot['loc'] == self.maze.destination:
                self.train_robot_statics['success'].append(1)
            else:
                self.train_robot_statics['success'].append(0)
            self.train_robot_statics['reward'].append(accumulated_reward)
            self.train_robot_statics['times'].append(run_time)
            self.maze.reset_robot()
            self.robot.reset()
#测试机器人能否走出迷宫
    def run_testing(self, testing_per_epoch):

        self.test_robot_statics = {}
        self.test_robot_statics['success'] = []
        self.test_robot_statics['reward'] = []
        self.test_robot_statics['times'] = []

        self.robot.set_status(learning=False, testing=True)

        testing_per_epoch = int(self.maze.height * self.maze.height * 0.85)
        accumulated_reward = 0.
        run_time = 0
        for i in range(testing_per_epoch):
            run_time += 1
            _, reward = self.robot.update()
            accumulated_reward += reward
            if self.maze.robot['loc'] == self.maze.destination:
                break
        if self.maze.robot['loc'] == self.maze.destination:
            self.test_robot_statics['success'].append(1)
        else:
            self.test_robot_statics['success'].append(0)
        self.test_robot_statics['reward'].append(accumulated_reward)
        self.test_robot_statics['times'].append(run_time)

#界面各项指标，图标的显示
    def draw_header(self, base_image):
        logo_size = 200 # 默认logo大小200
        logo_image = np.vstack((Image.new('RGB', (200,50), color=(255,255,255)),self.logo_img))# 图像的设置
        logo_image = np.vstack((logo_image,Image.new('RGB', (200,50), color=(255,255,255))))
        header_shape = (base_image.shape[1]-logo_size, logo_size+100) # 形状的高度和宽度
        header_img = np.hstack((logo_image, Image.new('RGB', header_shape, color=(255,255,255))))
        return header_img

# 在迷宫中绘制机器人
    def draw_robot(self, base_image, parameters):
        img = base_image.copy()
        robot = parameters['maze_loc']
        grid_size = 100
        r,c = robot['loc']
        img[r*grid_size:(r+1)*grid_size, c*grid_size:(c+1)*grid_size, :] += self.robot_img[robot['dir']]
        if self.display_direction:
            for state, q in parameters['Qtable'].items():
                r,c = state
                direction = max(q, key=q.get)
                img[r*grid_size:(r+1)*grid_size, c*grid_size:(c+1)*grid_size, :] = \
                    (0.3*self.arrow_img[direction] + 0.7*img[r*grid_size:(r+1)*grid_size, c*grid_size:(c+1)*grid_size, :]).astype('uint8')
        return img

# 界面的文字记录
    def write_on_header(self, header_img, parameters):
        header = Image.fromarray(header_img.copy())
        draw = ImageDraw.Draw(header)
        line0 = "Epoch %d \nTrain %d \n"%(parameters['id'][0]+1, parameters['id'][1]+1)
        line1 = "Robot current state %s \n"%(str(parameters['state']))
        line2 = "q value:" + ','.join([a + ": %.2f"%q for a,q in parameters['qtable'].items()])
        if not parameters['success']:
            line3 = "\nAction %s, Reward received %f \n"%(parameters['action'],parameters['reward'])
            line4 = "Epsilon: %.2f, Alpha: %.2f, Gamma: %.2f"%(parameters['epsilon'],parameters['alpha'],parameters['gamma'])
        else:
            line3, line4 = '', ''
        draw.text((230, 30), line0, (0,0,0), font=self.header_font)
        draw.text((230, 150), line1+line2+line3+line4, (0,0,0), font=self.font)

        return np.array(header)
#将训练结果生成视频
    def generate_movie(self, filename):

        base_image = self.maze.get_raw_maze_img()
        header_img = self.draw_header(base_image)
        def ensemble_image(train_id):
            new_header = self.write_on_header(header_img, self.train_robot_record[train_id])
            current_maze = self.draw_robot(base_image, self.train_robot_record[train_id])
            return (train_id, np.vstack((new_header, current_maze)))
        
        height, width, _ = ensemble_image((0,0))[1].shape
        writer = cv2.VideoWriter(filename, cv2.VideoWriter_fourcc(*"XVID"), 25.0, (width//2,height//2))

        #单线程导出视频
        # with tqdm.tqdm(sorted(self.train_robot_record.keys()), desc="Generate Movies") as pbar:
            #     for key in pbar:
            #         _, img = ensemble_image(key)
            #         writer.write(cv2.resize(img[:,:,::-1], (width//2, height//2)))

        # 多进程优化，内存使用优化：在工作流程之上构建的池之上模拟工作进程
        with Pool(processes=max(cpu_count()-1,1)) as pool:
            with tqdm.tqdm(pool.imap(ensemble_image, self.train_robot_record.keys()), total=len(self.train_robot_record.keys()), desc="Generate Movies") as pbar:
                for _, img in pbar:
                    writer.write(cv2.resize(img[:,:,::-1], (width//2, height//2)))

        writer.release()
#以图表展示训练过程中的指标
    def plot_results(self):
        plt.figure(figsize=(12,4))
        plt.subplot(131)
        plt.title("Success Times")
        plt.plot(np.cumsum(self.train_robot_statics['success']))
        plt.subplot(132)
        plt.title("Accumulated Rewards")
        plt.plot(np.array(self.train_robot_statics['reward']))
        plt.subplot(133)
        plt.title("Runing Times per Epoch")
        plt.plot(np.array(self.train_robot_statics['times']))
        plt.show()
        plt.savefig('resultPic.jpg')
