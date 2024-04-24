import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class testUI{
    public static void main(String[] args) {
        // 创建主窗口
        JFrame frame = new JFrame("班级人数控制");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 400);

        // 创建滚动面板
        JScrollPane scrollPane = new JScrollPane();
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        frame.getContentPane().add(scrollPane, BorderLayout.CENTER);

        // 创建面板用于放置滑动条
        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        scrollPane.setViewportView(panel);

        // 创建滑动条和标签的列表
        List<JSlider> sliderList = new ArrayList<>();
        List<JLabel> labelList = new ArrayList<>();

        // 添加班级和滑动条
        for (int i = 1; i <= 10; i++) {
            JLabel label = new JLabel("班级 " + i);
            GridBagConstraints gbcLabel = new GridBagConstraints();
            gbcLabel.gridx = 0;
            gbcLabel.gridy = i - 1;
            gbcLabel.anchor = GridBagConstraints.WEST;
            gbcLabel.insets = new Insets(5, 5, 5, 5);
            panel.add(label, gbcLabel);

            JSlider slider = new JSlider(JSlider.HORIZONTAL, 0, 100, 0);
            slider.setMajorTickSpacing(20);
            slider.setMinorTickSpacing(10);
            slider.setPaintTicks(true);
            slider.setPaintLabels(true);
            GridBagConstraints gbcSlider = new GridBagConstraints();
            gbcSlider.gridx = 1;
            gbcSlider.gridy = i - 1;
            gbcSlider.fill = GridBagConstraints.HORIZONTAL;
            gbcSlider.weightx = 1.0;
            gbcSlider.insets = new Insets(5, 5, 5, 5);
            panel.add(slider, gbcSlider);

            // 添加滑动条和标签到列表
            sliderList.add(slider);
            labelList.add(label);
        }

        // 添加按钮用于获取选中的人数
        JButton button = new JButton("获取人数");
        button.addActionListener(e -> {
            for (int i = 0; i < sliderList.size(); i++) {
                JSlider slider = sliderList.get(i);
                JLabel label = labelList.get(i);
                int value = slider.getValue();
                System.out.println(label.getText() + " 人数: " + value);
            }
        });
        frame.getContentPane().add(button, BorderLayout.SOUTH);

        // 显示窗口
        frame.setVisible(true);
    }
}
