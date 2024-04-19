import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.net.Socket;
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
        client = new Client();
        initComponents();
    }

    private void button1(ActionEvent e) {
        int number = Integer.parseInt(textField1.getText());
        String password = new String(passwordField1.getPassword());
        boolean flag = client.loginCheck(number, password);
        if (flag) {
            dispose();
            new Client_Student().setVisible(true);
        } else {

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
        contentPane.add(label1);
        label1.setBounds(new Rectangle(new Point(200, 20), label1.getPreferredSize()));

        //---- label2 ----
        label2.setText(bundle.getString("label2.text"));
        contentPane.add(label2);
        label2.setBounds(new Rectangle(new Point(65, 100), label2.getPreferredSize()));

        //---- label3 ----
        label3.setText(bundle.getString("label3.text"));
        contentPane.add(label3);
        label3.setBounds(new Rectangle(new Point(65, 135), label3.getPreferredSize()));
        contentPane.add(textField1);
        textField1.setBounds(120, 85, 235, textField1.getPreferredSize().height);
        contentPane.add(passwordField1);
        passwordField1.setBounds(115, 145, 235, passwordField1.getPreferredSize().height);

        //---- button1 ----
        button1.setText(bundle.getString("button1.text"));
        button1.addActionListener(e -> button1(e));
        contentPane.add(button1);
        button1.setBounds(new Rectangle(new Point(95, 240), button1.getPreferredSize()));

        //---- button2 ----
        button2.setText(bundle.getString("button2.text"));
        contentPane.add(button2);
        button2.setBounds(new Rectangle(new Point(300, 250), button2.getPreferredSize()));

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
        pack();
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
            new Client_StudentLogin().setVisible(true);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
