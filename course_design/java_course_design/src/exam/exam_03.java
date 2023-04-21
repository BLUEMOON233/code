package exam;

import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class exam_03 {
    static float sum = 0f;
    private JFrame frame;
    private JTextField textField;

    public exam_03() {
        init_action();
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    exam_03 window = new exam_03();
                    window.frame.setVisible(true);
                } catch (Exception exc) {
                    exc.printStackTrace();
                }
            }
        });
    }

    private void init_action() {
        frame = new JFrame();
        frame.setTitle("计算器");
        frame.setResizable(false);
        frame.setBounds(550, 500, 360, 450);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        JButton button_01 = new JButton("1");
        button_01.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent arg0) {
                textField.setText(textField.getText() + 1);
            }
        });
        button_01.setBounds(70, 100, 50, 50);
        frame.getContentPane().add(button_01);

        JButton button_02 = new JButton("2");
        button_02.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + 2);
            }
        });
        button_02.setBounds(120, 100, 50, 50);
        frame.getContentPane().add(button_02);

        JButton button_03 = new JButton("3");
        button_03.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + 3);
            }
        });
        button_03.setBounds(170, 100, 50, 50);
        frame.getContentPane().add(button_03);

        JButton button_04 = new JButton("4");
        button_04.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + 4);
            }
        });
        button_04.setBounds(70, 150, 50, 50);
        frame.getContentPane().add(button_04);

        JButton button_05 = new JButton("5");
        button_05.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + 5);
            }
        });
        button_05.setBounds(120, 150, 50, 50);
        frame.getContentPane().add(button_05);

        JButton button_06 = new JButton("6");
        button_06.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + 6);
            }
        });
        button_06.setBounds(170, 150, 50, 50);
        frame.getContentPane().add(button_06);

        JButton button_07 = new JButton("7");
        button_07.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + 7);
            }
        });
        button_07.setBounds(70, 200, 50, 50);
        frame.getContentPane().add(button_07);

        JButton button_08 = new JButton("8");
        button_08.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + 8);
            }
        });
        button_08.setBounds(120, 200, 50, 50);
        frame.getContentPane().add(button_08);

        JButton button_09 = new JButton("9");
        button_09.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + 9);
            }
        });
        button_09.setBounds(170, 200, 50, 50);
        frame.getContentPane().add(button_09);

        JButton button_00 = new JButton("0");
        button_00.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + 0);
            }
        });
        button_00.setBounds(70, 250, 50, 50);
        frame.getContentPane().add(button_00);

        //加法：
        JButton button_plus = new JButton("+");
        button_plus.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + " + ");
                String str = textField.getText();
                String[] stringArr = str.split((" "));
                if (stringArr.length == 2) {
                    float i = Float.valueOf(stringArr[0]);
                    sum = i;
                } else if (stringArr[stringArr.length - 3].equals("+")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum + i;
                } else if (stringArr[stringArr.length - 3].equals("-")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum - i;
                } else if (stringArr[stringArr.length - 3].equals("*")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum * i;
                } else if (stringArr[stringArr.length - 3].equals("/")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum / i;
                }
            }
        });
        button_plus.setBounds(220, 150, 50, 50);
        frame.getContentPane().add(button_plus);

        //减法：
        JButton button_sub = new JButton("-");
        button_sub.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + " - ");
                String str = textField.getText();
                String[] stringArr = str.split((" "));
                if (stringArr.length == 2) {
                    float i = Float.valueOf(stringArr[0]);
                    sum = i;
                } else if (stringArr[stringArr.length - 3].equals("+")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum + i;
                } else if (stringArr[stringArr.length - 3].equals("-")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum - i;
                } else if (stringArr[stringArr.length - 3].equals("*")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum * i;
                } else if (stringArr[stringArr.length - 3].equals("/")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum / i;
                }
            }
        });
        button_sub.setBounds(220, 200, 50, 50);
        frame.getContentPane().add(button_sub);

        //乘法：
        JButton button_mult = new JButton("*");
        button_mult.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + " * ");
                String str = textField.getText();
                String[] stringArr = str.split((" "));
                if (stringArr.length == 2) {
                    float i = Float.valueOf(stringArr[0]);
                    sum = i;
                } else if (stringArr[stringArr.length - 3].equals("+")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum + i;
                } else if (stringArr[stringArr.length - 3].equals("-")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum - i;
                } else if (stringArr[stringArr.length - 3].equals("*")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum * i;
                } else if (stringArr[stringArr.length - 3].equals("/")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum / i;
                }
            }
        });
        button_mult.setBounds(220, 100, 50, 50);
        frame.getContentPane().add(button_mult);

        //除法：
        JButton button_div = new JButton("/");
        button_div.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + " / ");
                String str = textField.getText();
                String[] stringArr = str.split((" "));
                if (stringArr.length == 2) {
                    float i = Float.valueOf(stringArr[0]);
                    sum = i;
                } else if (stringArr[stringArr.length - 3].equals("+")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum + i;
                } else if (stringArr[stringArr.length - 3].equals("-")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum - i;
                } else if (stringArr[stringArr.length - 3].equals("*")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum * i;
                } else if (stringArr[stringArr.length - 3].equals("/")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum / i;
                }
            }
        });
        button_div.setBounds(120, 250, 50, 50);
        frame.getContentPane().add(button_div);

        //计算:
        JButton button_cal = new JButton("=");
        button_cal.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText(textField.getText() + " = ");
                String str = textField.getText();
                String[] stringArr = str.split((" "));
                if (stringArr.length == 2) {
                    float i = Float.valueOf(stringArr[0]);
                    sum = i;
                    textField.setText(textField.getText() + sum);
                } else if (stringArr[stringArr.length - 3].equals("+")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum + i;
                    textField.setText(textField.getText() + sum);
                } else if (stringArr[stringArr.length - 3].equals("-")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum - i;
                    textField.setText(textField.getText() + sum);
                } else if (stringArr[stringArr.length - 3].equals("*")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum * i;
                    textField.setText(textField.getText() + sum);
                } else if (stringArr[stringArr.length - 3].equals("/")) {
                    float i = Float.valueOf(stringArr[stringArr.length - 2]);
                    sum = sum / i;
                    textField.setText(textField.getText() + sum);
                }
            }
        });
        button_cal.setBounds(170, 250, 50, 50);
        frame.getContentPane().add(button_cal);

        textField = new JTextField();
        textField.setBounds(70, 50, 200, 50);
        frame.getContentPane().add(textField);
        textField.setColumns(10);

        JButton button_point = new JButton(".");
        button_point.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent arg0) {
                textField.setText(textField.getText() + ".");
            }
        });
        button_point.setBounds(220, 250, 50, 50);
        frame.getContentPane().add(button_point);

        JButton button_delete = new JButton("清空");
        button_delete.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textField.setText("");
                sum = 0;
            }
        });
        button_delete.setBounds(70, 300, 200, 50);
        frame.getContentPane().add(button_delete);
    }
}
