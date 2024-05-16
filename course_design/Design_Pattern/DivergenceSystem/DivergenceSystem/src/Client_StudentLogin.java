import com.formdev.flatlaf.themes.FlatMacLightLaf;

import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.util.*;
import javax.swing.*;
/*
 * Created by JFormDesigner on Fri Apr 19 21:58:35 CST 2024
 */


/**
 * @author liuwy
 */
public class Client_StudentLogin extends JFrame {
    private Client client = null;

    public Client_StudentLogin() throws IOException {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        client = new Client();
        initComponents();
    }

    private void button1(ActionEvent e) {
        int number = Integer.parseInt(textField1.getText());
        String password = new String(passwordField1.getPassword());
        boolean flag = client.loginCheck(number, password);
        if (flag) {
            dispose();
            try {
                new Client_Student(number).setVisible(true);
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        } else {
            System.out.println("登录失败！");
        }
    }

    private void initComponents() {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents  @formatter:off
        ResourceBundle bundle = ResourceBundle.getBundle("Client_Student");
        label1 = new JLabel();
        label2 = new JLabel();
        label3 = new JLabel();
        textField1 = new JTextField();
        passwordField1 = new JPasswordField();
        button1 = new JButton();
        button2 = new JButton();

        //======== this ========
        var contentPane = getContentPane();
        contentPane.setLayout(null);

        //---- label1 ----
        label1.setText(bundle.getString("label1.text"));
        label1.setFont(new Font("\u5fae\u8f6f\u96c5\u9ed1", Font.PLAIN, 25));
        contentPane.add(label1);
        label1.setBounds(180, 20, 155, 45);

        //---- label2 ----
        label2.setText(bundle.getString("label2.text"));
        label2.setFont(new Font("\u65b0\u5b8b\u4f53", Font.PLAIN, 20));
        contentPane.add(label2);
        label2.setBounds(110, 90, 70, 30);

        //---- label3 ----
        label3.setText(bundle.getString("label3.text"));
        label3.setFont(new Font("\u65b0\u5b8b\u4f53", Font.PLAIN, 20));
        contentPane.add(label3);
        label3.setBounds(110, 140, 70, 30);
        contentPane.add(textField1);
        textField1.setBounds(195, 85, 235, 40);
        contentPane.add(passwordField1);
        passwordField1.setBounds(195, 140, 235, 40);

        //---- button1 ----
        button1.setText(bundle.getString("button1.text"));
        button1.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 20));
        button1.addActionListener(e -> button1(e));
        contentPane.add(button1);
        button1.setBounds(85, 220, 125, 50);

        //---- button2 ----
        button2.setText(bundle.getString("button2.text"));
        button2.setFont(new Font("Microsoft YaHei UI", Font.PLAIN, 20));
        contentPane.add(button2);
        button2.setBounds(265, 220, 125, 50);

        contentPane.setPreferredSize(new Dimension(400, 300));
        setSize(500, 375);
        setLocationRelativeTo(getOwner());
        // JFormDesigner - End of component initialization  //GEN-END:initComponents  @formatter:on
    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables  @formatter:off
    private JLabel label1;
    private JLabel label2;
    private JLabel label3;
    private JTextField textField1;
    private JPasswordField passwordField1;
    private JButton button1;
    private JButton button2;
    // JFormDesigner - End of variables declaration  //GEN-END:variables  @formatter:on

    public static void main(String[] args) {
        try {
            FlatMacLightLaf.setup();
            new Client_StudentLogin().setVisible(true);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
