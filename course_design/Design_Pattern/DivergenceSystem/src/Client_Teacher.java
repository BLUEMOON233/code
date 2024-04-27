import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import javax.swing.*;
/*
 * Created by JFormDesigner on Wed Apr 24 22:09:42 CST 2024
 */


/**
 * @author liuwy
 */
public class Client_Teacher extends JFrame {
    Client client = null;
    Map<Integer, JSpinner> mapSpinner;

    public Client_Teacher() throws IOException {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        client = new Client();
        mapSpinner = new HashMap<>();
        initComponents();
        Init();
    }

    void Init() {
        initMajorInfo();
        tabbedPane1.addChangeListener(e -> {
            int selectedIndex = tabbedPane1.getSelectedIndex();
//            System.out.println("切换到Tab页: " + tabbedPane1.getTitleAt(selectedIndex));
            if (selectedIndex == 0) initMajorInfo();
        });

    }

    public void initMajorInfo() {
        mapSpinner.clear();
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(0, 1));
        JViewport viewport = majorInfo.getViewport();
        List<UndivertedStudent> majorList = client.getMajorClass();
        for (UndivertedStudent major : majorList) {
//            System.out.println(major);
            JPanel row = new JPanel(new BorderLayout());
            row.setSize(100, 30);
            JLabel label = new JLabel(String.valueOf(major.number) + "-" + major.name + ": ");
            row.add(label, BorderLayout.WEST);
            JSpinner spinner = new JSpinner();
            spinner.setValue(Integer.parseInt(major.gender));
            mapSpinner.put(major.number, spinner);
            row.add(spinner, BorderLayout.EAST);
            panel.add(row);
        }
        viewport.add(panel);
    }

    public void initClassInfo() {

    }

    private void BT_addMajor(ActionEvent e) {
        String input = JOptionPane.showInputDialog(null, "请输入专业名称:");
        client.addMajor(input);
        initMajorInfo();
    }

    private void BT_delMajor(ActionEvent e) {
        String input = JOptionPane.showInputDialog(null, "请输入专业对应代码:");
        int value = Integer.parseInt(input);
        client.delMajor(value);
        initMajorInfo();
    }

    private void BT_saveMajor(ActionEvent e) {
        for (Map.Entry<Integer, JSpinner> entry : mapSpinner.entrySet()) {
            client.modifyMajor(entry.getKey(), (int) entry.getValue().getValue());
        }
        initMajorInfo();
        client.initClass();
    }

    private void initComponents() {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents  @formatter:off
        tabbedPane1 = new JTabbedPane();
        TP_settings = new JPanel();
        majorInfo = new JScrollPane();
        BT_addMajor = new JButton();
        BT_delMajor = new JButton();
        BT_saveMajor = new JButton();
        classInfo = new JScrollPane();
        TP_filInfo = new JScrollPane();

        //======== this ========
        var contentPane = getContentPane();
        contentPane.setLayout(null);

        //======== tabbedPane1 ========
        {

            //======== TP_settings ========
            {
                TP_settings.setLayout(null);
                TP_settings.add(majorInfo);
                majorInfo.setBounds(50, 80, 400, 195);

                //---- BT_addMajor ----
                BT_addMajor.setText("\u6dfb\u52a0\u4e13\u4e1a");
                BT_addMajor.addActionListener(e -> BT_addMajor(e));
                TP_settings.add(BT_addMajor);
                BT_addMajor.setBounds(50, 20, 130, 55);

                //---- BT_delMajor ----
                BT_delMajor.setText("\u5220\u9664\u4e13\u4e1a");
                BT_delMajor.addActionListener(e -> BT_delMajor(e));
                TP_settings.add(BT_delMajor);
                BT_delMajor.setBounds(185, 20, 130, 55);

                //---- BT_saveMajor ----
                BT_saveMajor.setText("\u4fdd\u5b58\u4e13\u4e1a");
                BT_saveMajor.addActionListener(e -> BT_saveMajor(e));
                TP_settings.add(BT_saveMajor);
                BT_saveMajor.setBounds(320, 20, 130, 55);
                TP_settings.add(classInfo);
                classInfo.setBounds(50, 295, 400, 400);
            }
            tabbedPane1.addTab("\u8bbe\u7f6e", TP_settings);
            tabbedPane1.addTab("\u5b66\u751f\u586b\u62a5\u4fe1\u606f", TP_filInfo);
        }
        contentPane.add(tabbedPane1);
        tabbedPane1.setBounds(35, 10, 950, 770);

        contentPane.setPreferredSize(new Dimension(820, 660));
        pack();
        setLocationRelativeTo(getOwner());
        // JFormDesigner - End of component initialization  //GEN-END:initComponents  @formatter:on
    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables  @formatter:off
    private JTabbedPane tabbedPane1;
    private JPanel TP_settings;
    private JScrollPane majorInfo;
    private JButton BT_addMajor;
    private JButton BT_delMajor;
    private JButton BT_saveMajor;
    private JScrollPane classInfo;
    private JScrollPane TP_filInfo;
    // JFormDesigner - End of variables declaration  //GEN-END:variables  @formatter:on

    public static void main(String[] args) {
        try {
            new Client_Teacher().setVisible(true);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
