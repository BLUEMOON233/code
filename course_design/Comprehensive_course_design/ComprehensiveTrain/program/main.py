from Maze import Maze
from Robot import Robot
from Runner import Runner
from PySide6.QtWidgets import QMainWindow, QApplication
from ui import Ui_MainWindow
import cv2

class MyMainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

    def startTraining(self):
        """
        开始训练
        """
        g = Maze(
            maze_size=(int(self.ui.lineEdit_mazeLon.text()), int(self.ui.lineEdit_mazeWid.text())), 
            trap_num=int(self.ui.lineEdit_trapNumber.text())
            )
        r = Robot(
            maze = g,
            alpha = float(self.ui.lineEdit_alpha.text()),
            epsilon0 = float(self.ui.lineEdit_epsilon0.text()),
            gamma = float(self.ui.lineEdit_gamma.text())
            )
        r.set_status(learning=True)

        runner = Runner(r, g)
        runner.run_training(int(self.ui.lineEdit_epoch.text()), display_direction=True)
        runner.generate_movie(filename = "finalResult.mp4")
        runner.plot_results()

        cap = cv2.VideoCapture('finalResult.mp4')
        while(cap.isOpened()):
            ret, frame = cap.read()
            if ret:
                cv2.imshow('Training Result', frame)  
                cv2.waitKey(30)
            else:
                break
        cap.release()  
        cv2.destroyAllWindows()

    def changeDifficulty(self):
        self.ui.stackedWidget.setCurrentIndex((self.ui.stackedWidget.currentIndex() + 1) % 3)
        if self.ui.stackedWidget.currentIndex() == 0:
            self.ui.lineEdit_mazeLon.setText('7')
            self.ui.lineEdit_mazeWid.setText('7')
            self.ui.lineEdit_trapNumber.setText('1')
            self.ui.lineEdit_epoch.setText('25')
        elif self.ui.stackedWidget.currentIndex() == 1:
            self.ui.lineEdit_mazeLon.setText('7')
            self.ui.lineEdit_mazeWid.setText('12')
            self.ui.lineEdit_trapNumber.setText('2')
            self.ui.lineEdit_epoch.setText('35')
        else:
            self.ui.lineEdit_mazeLon.setText('12')
            self.ui.lineEdit_mazeWid.setText('12')
            self.ui.lineEdit_trapNumber.setText('3')
            self.ui.lineEdit_epoch.setText('50')



if __name__ == "__main__":
    app = QApplication()
    window = MyMainWindow()
    window.show()
    app.exec_()