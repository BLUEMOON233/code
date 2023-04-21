package exam;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.JFrame;
import javax.swing.Timer;

public class exam_04 {
    JFrame frame = new JFrame();
    Random rand = new Random();
    MyCanvas tableArea = new MyCanvas();
    Timer timer;
    //参数设置：
    int table_W = 300, table_H = 400;
    int board_Y = 350, board_W = 60;
    int ball_size = 16;
    int speed_Y = 10;
    double rate_XY = rand.nextDouble() - 0.5;
    int speed_X = (int) (speed_Y * rate_XY * 2);
    int ball_X = rand.nextInt(200) + 20;
    int ball_Y = rand.nextInt(10) + 20;
    int board_X = rand.nextInt(200);
    boolean end_flag = false;

    public static void main(String[] args) {
        new exam_04().init();
    }

    public void init() {
        frame.setTitle("网球小游戏");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        tableArea.setSize((new Dimension(table_W, table_H)));
        frame.add(tableArea);
        frame.setResizable(false);

        KeyAdapter key_adapter = new KeyAdapter() {
            public void keyPressed(KeyEvent action) {
                if (action.getKeyCode() == KeyEvent.VK_LEFT && board_X > 0) board_X -= 10;
                if (action.getKeyCode() == KeyEvent.VK_RIGHT && board_X < table_W - board_W) board_X += 10;
            }
        };

        frame.addKeyListener(key_adapter);
        tableArea.addKeyListener(key_adapter);
        ActionListener listener = evt -> {
            if (ball_X <= 0 || ball_X >= table_W - ball_size) speed_X = -speed_X;
            if (ball_Y <= 0 || (ball_Y > board_Y - ball_size && ball_X > board_X && ball_X <= board_X + board_W)) speed_Y = -speed_Y;
            ball_Y += speed_Y;
            ball_X += speed_X;
            if (ball_Y >= board_Y - ball_size && (ball_X < board_X || ball_X > board_X + board_W)) {
                timer.stop();
                end_flag = true;
            }
            tableArea.repaint();
        };
        timer = new Timer(100, listener);
        timer.start();
        frame.pack();
        frame.setVisible(true);

    }

    class MyCanvas extends Canvas {
        long serialVersionUID = 1L;

        public void paint(Graphics graph) {
            if (end_flag) {
                graph.setColor(Color.red);
                graph.setFont(new Font("Times New Roman", Font.CENTER_BASELINE, 30));
                graph.drawString("GAME OVER", 50, 200);
            } else {
                graph.setColor(Color.BLACK);
                graph.fillOval(ball_X, ball_Y, ball_size, ball_size);
                graph.fillRect(board_X, board_Y, board_W, 10);
            }
        }
    }
}
