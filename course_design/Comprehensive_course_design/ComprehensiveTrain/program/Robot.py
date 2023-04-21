import random

class Robot(object):
    def __init__(
            self,
            maze,
            alpha=0.5,
            gamma=0.9,
            epsilon0=0.5
        ):  #设置默认松张变量，折扣因子，概率
        self.maze = maze  #机器人所在迷宫对象
        self.valid_actions = self.maze.valid_actions  #可进行的action
        #初始化机器人状态和动作
        self.state = None
        self.action = None

        self.alpha = alpha  #学习率
        self.gamma = gamma  #折扣因子

        self.epsilon0 = epsilon0  #初始探索概率
        self.epsilon = epsilon0  #探索概率，和动作选择有关
        self.t = 0  #已探索次数
        self.Qtable = {}  #Q table表
        self.reset()

    def reset(self):
        """
        初始化机器人
        """
        self.state = self.sense_state()
        self.create_Qtable_line(self.state)

    def set_status(self, learning=False, testing=False):
        """
        确定机器人是否在学习q表, 
        或执行测试程序。
        """
        self.learning = learning
        self.testing = testing

    def update_parameter(self):
        """
        q学习机器人的一些参数可以被改变,
        必要时更新这些参数。
        """
        if self.testing:
            #如果不是探索状态，则跳过
            pass
        else:
            self.t += 1
            if self.epsilon < 0.01:
                self.epsilon = 0.01
            else:
                self.epsilon -= self.t * 0.1
                #根据已探索次数减少探索概率
        return self.epsilon

    def sense_state(self):
        """
        返回机器人当前状态
        """
        return self.maze.sense_robot()

    def create_Qtable_line(self, state):
        """
        在Qtable中添加新行
        """
        if state in self.Qtable: #机器人状态存在
            pass
        else:
            self.Qtable[state] = {'u': 0.0, 'r': 0.0, 'd': 0.0, 'l': 0.0}

    def choose_action(self):
        """
        机器人进行动作选择，返回选择的动作
        """
        def is_random_exploration():
            #随机选择是否进行探索
            return random.random() < self.epsilon

        if self.learning:  #机器人进行探索情况
            if is_random_exploration():  #进行探索
                action = random.choice(self.valid_actions)  #随机选择一个动作进行探索
                print("random: ", action)
                return action
            else:  #不进行探索
                action = max(
                    self.Qtable[self.state],
                    key=self.Qtable[self.state].get
                    )  #返回Qtable表中有着最大价值的action
                print("train", action)
                return action
        elif self.testing:  #机器人进行利用情况
            action = max(
                self.Qtable[self.state],
                key=self.Qtable[self.state].get
                )
            print("text:", action)
            return action
        else:
            action = random.choice(self.valid_actions)
            print("non_all", action)
            return action

    def update_Qtable(self, r, action, next_state):
        """
        依据当前规则更新Qtable
        """
        if self.learning:  #在探索情况下才更新
            current_r = self.Qtable[self.state][action]  #获取当前的回报
            update_r = r + (self.gamma * float(max(self.Qtable[next_state].values())))  #获取更新的回报
            self.Qtable[self.state][action] += self.alpha * (update_r - current_r)  #写入Qtable表

    def update(self):
        """
        机器人Qtable表更新函数，返回现在的动作和奖励
        """
        self.state = self.sense_state()  #获取现在的状态
        self.create_Qtable_line(self.state)  #如果当前状态不在Q table中，则添加进去
        action = self.choose_action()  #针对当前状态选择动作
        reward = self.maze.move_robot(action)  #根据选择的动作在迷宫中移动机器人
        next_state = self.sense_state()  #获取下一状态
        self.create_Qtable_line(next_state)  #如果下一状态不在Q table中，则添加进去

        if self.learning and not self.testing:  #如果是学习状态
            self.update_Qtable(reward, action, next_state)  #更新Qtable表
            self.update_parameter()  #减少探索概率，并更新该参数
        return action, reward
