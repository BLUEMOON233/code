import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import javax.swing.*;
/*
 * Created by JFormDesigner on Wed Apr 24 21:44:39 CST 2024
 */



/**
 * @author liuwy
 */
public class Client_TeacherLogin extends JFrame {
    Client client = null;
    public Client_TeacherLogin() throws IOException {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        client = new Client();
        initComponents();
    }

    private void BT_login(ActionEvent e) {
        int number = Integer.parseInt(textField1.getText());
        String password = new String(passwordField1.getPassword());
        boolean flag = client.adminLoginCheck(number, password);
        if (flag) {
            dispose();
            try {
                new Client_Teacher().setVisible(true);
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        } else {
            System.out.println("登录失败！");
        }
    }

    private void initComponents() {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents  @formatter:off
        BT_login = new JButton();
        label1 = new JLabel();
        label2 = new JLabel();
        passwordField1 = new JPasswordField();
        textField1 = new JTextField();
        label3 = new JLabel();

        //======== this ========
        var contentPane = getContentPane();
        contentPane.setLayout(null);

        //---- BT_login ----
        BT_login.setText("\u767b\u5f55");
        BT_login.addActionListener(e -> BT_login(e));
        contentPane.add(BT_login);
        BT_login.setBounds(190, 250, 130, 55);

        //---- label1 ----
        label1.setText("\u6559\u5e08\u8d26\u53f7\uff1a");
        contentPane.add(label1);
        label1.setBounds(45, 70, 85, 50);

        //---- label2 ----
        label2.setText("\u5bc6       \u7801\uff1a");
        contentPane.add(label2);
        label2.setBounds(45, 120, 85, 50);
        contentPane.add(passwordField1);
        passwordField1.setBounds(145, 130, 185, passwordField1.getPreferredSize().height);
        contentPane.add(textField1);
        textField1.setBounds(145, 85, 175, textField1.getPreferredSize().height);

        //---- label3 ----
        label3.setText("\u6559\u5e08\u7aef\u767b\u5f55");
        contentPane.add(label3);
        label3.setBounds(120, 30, 205, 35);

        {
            // compute preferred size
            Dimension preferredSize = new Dimension();
            for(int i = 0; i < contentPane.getComponentCount(); i++) {
                Rectangle bounds = contentPane.getComponent(i).getBounds();
                preferredSize.width = Math.max(bounds.x + bounds.width, preferredSize.width);
                preferredSize.height = Math.max(bounds.y + bounds.height, preferredSize.height);
            }
            Insets insets = contentPane.getInsets();
            preferredSize.width += insets.right;
            preferredSize.height += insets.bottom;
            contentPane.setMinimumSize(preferredSize);
            contentPane.setPreferredSize(preferredSize);
        }
        setSize(500, 375);
        setLocationRelativeTo(getOwner());
        // JFormDesigner - End of component initialization  //GEN-END:initComponents  @formatter:on
    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables  @formatter:off
    private JButton BT_login;
    private JLabel label1;
    private JLabel label2;
    private JPasswordField passwordField1;
    private JTextField textField1;
    private JLabel label3;
    // JFormDesigner - End of variables declaration  //GEN-END:variables  @formatter:on

    public static void main(String[] args){
        try {
            new Client_TeacherLogin().setVisible(true);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
