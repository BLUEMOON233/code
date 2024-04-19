import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Client_Student {
    private JPanel root;
    private JButton 登陆Button;
    private JButton 退出Button;
    private JTextField textField1;
    private JPasswordField passwordField1;

    public Client_Student() {
        登陆Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("yep");
            }
        });
    }

    public static void main(String[] args) {
        JFrame jFrame = new JFrame("Test");
        jFrame.setContentPane(new Client_Student().root);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jFrame.pack();
        jFrame.setVisible(true);
    }
}
