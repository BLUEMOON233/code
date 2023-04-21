import random

class Robot(object):
    def __init__(self, maze, alpha=0.5, gamma=0.9, epsilon0=0.5):    #设置默认松张变量，折扣因子，概率
        #机器人所在迷宫对象
        self.maze = maze
        #可进行的action
        self.valid_actions = self.maze.valid_actions
        #初始化机器人状态和动作
        self.state = None
        self.action = None
        
        self.alpha = alpha    #学习率
        self.gamma = gamma    #折扣因子

        self.epsilon0 = epsilon0
        self.epsilon = epsilon0
        self.t = 0

        self.Qtable = {}
        self.reset()

    def reset(self):
        """
        Reset the robot
        """
        self.state = self.sense_state()
        self.create_Qtable_line(self.state)

    def set_status(self, learning=False, testing=False):
        """
        Determine whether the robot is learning its q table, or
        exceuting the testing procedure.
        """
        self.learning = learning
        self.testing = testing

    def update_parameter(self):
        """
        Some of the paramters of the q learning robot can be altered,
        update these parameters when necessary.
        """
        if self.testing:
            # When testing do not update anything
            pass
        else:
            # damping the random choose
            self.t += 1
            if self.epsilon < 0.01:
                self.epsilon = 0.01
            else:
                self.epsilon -= self.t*0.1

        return self.epsilon

    def sense_state(self):
        """
        Get the current state of the robot. In this
        """
        # TODO 3. Return robot's current state
        return self.maze.sense_robot()

    def create_Qtable_line(self, state):
        """
        Create the qtable with the current state
        """
        # TODO 4. Create qtable with current state
        # Our qtable should be a two level dict,
        # Qtable[state] ={'u':xx, 'd':xx, ...}
        # If Qtable[state] already exits, then do
        # not change it.
        if state in self.Qtable:
            pass
        else:
            self.Qtable[state] = {'u':0.0, 'r':0.0, 'd':0.0, 'l':0.0}

    def choose_action(self):
        """
        Return an action according to given rules
        """
        def is_random_exploration():

            # TODO 5. Return whether do random choice
            # hint: generate a random number, and compare
            # it with epsilon
            return random.random()<self.epsilon

        if self.learning:
            if is_random_exploration():
                # TODO 6. Return random choose aciton
                action = random.choice(self.valid_actions)
                print("random:", action)
                return action
            else:
                # TODO 7. Return action with highest q value
                action = max(self.Qtable[self.state], key=self.Qtable[self.state].get)
                print("train:", action)
                return action
        elif self.testing:
            # get current state
                action = max(self.Qtable[self.state], key=self.Qtable[self.state].get)
                print("test:", action)
                return action
        else:
            action = random.choice(self.valid_actions)
            print("non_all:", action)
            return action

    def update_Qtable(self, r, action, next_state):
        """
        Update the qtable according to the given rule.
        """
        if self.learning:
            # TODO 8. When learning, update the q table according
            # to the given rules
            # current reward
            current_r = self.Qtable[self.state][action]
            # update reward
            update_r = r + (self.gamma * float(max(self.Qtable[next_state].values())))
            # write in Qtable
            self.Qtable[self.state][action] += self.alpha * ( update_r - current_r)
            
    def update(self):
        """
        Describle the procedure what to do when update the robot.
        Called every time in every epoch in training or testing.
        Return current action and reward.
        """
        self.state = self.sense_state() # Get the current state
        self.create_Qtable_line(self.state) # For the state, create q table line

        action = self.choose_action() # choose action for this state
        reward = self.maze.move_robot(action) # move robot for given action

        next_state = self.sense_state() # get next state
        self.create_Qtable_line(next_state) # create q table line for next state

        if self.learning and not self.testing:
            self.update_Qtable(reward, action, next_state) # update q table
            self.update_parameter() # update parameters

        return action, reward
