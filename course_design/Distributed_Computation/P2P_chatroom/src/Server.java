import javax.swing.*;
import java.awt.*;
import java.io.IOException;
import java.net.ServerSocket;
import java.util.Vector;

public class Server extends JFrame {
    private StringBuilder systemLog = new StringBuilder();       //系统记录
    private Vector<String> onlineUser;    //在线用户
    private boolean isStop;      //是否关闭服务器---线程关闭
    public OnlineOfflineMessage onlineMessage;  //上线消息
    public OnlineOfflineMessage offlineMessage; //下线消息
    //UI对象
    private JTextArea systemLogTextArea;   //聊天记录组件
    private JTextArea sendMessageTextArea;  //发送消息组件
    private JTextField onlineCountTextFile; //在线人数组件
    private JList<String> onlineUserList;         //在线用户组件
    private JButton sendMessageButton;      //发送消息组件
    private JButton clearMessageButton;     //清空消息组件
    private JButton startServerButton;                //启动服务器组件
    private JButton shutDownServerButton;               //关闭服务器组件

    public boolean isStop() {
        return isStop;
    }

    public void setSystemLog(StringBuilder systemLog) {
        this.systemLog = systemLog;
        systemLogTextArea.setText(String.valueOf(systemLog));
    }

    public Server(String title) throws HeadlessException {
        super(title);
        this.setSize(700, 500);        //窗口大小
        this.setLocationRelativeTo(null);
        this.setResizable(false);                  //不可变大小
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  //关闭按钮

        JPanel panel = new JPanel();
        panel.setLayout(null);
        this.init(panel);
        this.getContentPane().add(panel);
        this.setVisible(true);               //可见
        this.eventListener();
    }

    public void init(JPanel panel) {
        JLabel label1 = new JLabel("系统记录");
        label1.setBounds(5, 0, 492, 25);
        panel.add(label1);

        systemLogTextArea = new JTextArea();
        systemLogTextArea.setEditable(false);
        systemLogTextArea.setBackground(Color.LIGHT_GRAY);
        JScrollPane systemLogScrollPane = new JScrollPane(systemLogTextArea);
        systemLogScrollPane.setBounds(5, 26, 492, 300);
        systemLogScrollPane.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        panel.add(systemLogScrollPane);

        sendMessageTextArea = new JTextArea();
        sendMessageTextArea.setBackground(Color.LIGHT_GRAY);
        JScrollPane sendMessageScrollPane = new JScrollPane(sendMessageTextArea);
        sendMessageScrollPane.setBounds(5, 330, 492, 98);
        panel.add(sendMessageScrollPane);

        sendMessageButton = new JButton();
        sendMessageButton.setText("发送");
        sendMessageButton.setBounds(5, 430, 200, 30);
        sendMessageButton.setEnabled(false);
        panel.add(sendMessageButton);

        clearMessageButton = new JButton();
        clearMessageButton.setText("清除");
        clearMessageButton.setBounds(295, 430, 200, 30);
        clearMessageButton.setEnabled(false);
        panel.add(clearMessageButton);

        JLabel onlineLabel = new JLabel("在线用户列表");
        onlineLabel.setBounds(500, 0, 182, 25);
        panel.add(onlineLabel);

        onlineCountTextFile = new JTextField();
        onlineCountTextFile.setText("在线用户0人");
        onlineCountTextFile.setBounds(500, 26, 182, 25);
        onlineCountTextFile.setBackground(Color.LIGHT_GRAY);
        onlineCountTextFile.setOpaque(true);
        panel.add(onlineCountTextFile);

        onlineUser = new Vector<>();
        onlineUserList = new JList<>(onlineUser);
        onlineUserList.setBounds(500, 52, 182, 340);
        onlineUserList.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        onlineUserList.setBackground(Color.lightGray);
        panel.add(onlineUserList);

        startServerButton = new JButton();
        startServerButton.setText("启动服务器");
        startServerButton.setBounds(500, 396, 182, 32);
        panel.add(startServerButton);

        shutDownServerButton = new JButton();
        shutDownServerButton.setText("关闭服务器");
        shutDownServerButton.setBounds(500, 430, 182, 30);
        shutDownServerButton.setEnabled(false);
        panel.add(shutDownServerButton);
    }

    public void eventListener() {
        //发送消息
        sendMessageButton.addActionListener(event -> {
        });

        //清空消息
        clearMessageButton.addActionListener(event -> sendMessageTextArea.setText(null));

        //启动服务器
        startServerButton.addActionListener(event -> {
            startServer();
        });

        //关闭服务器
        shutDownServerButton.addActionListener(event -> {
            isStop = true;
            System.exit(0);
        });
    }

    public void startServer() {
        try {
            ServerSocket serverSocket = new ServerSocket(1234);      //启动服务器
            systemLog.append("等待连接......" + "\n");
            setSystemLog(systemLog);

            startServerButton.setEnabled(false);
            shutDownServerButton.setEnabled(true);
            sendMessageButton.setEnabled(true);
            clearMessageButton.setEnabled(true);
            this.isStop = false;
            //在线用户列表
            UserInfo userInfo = new UserInfo();
            //创建服务器端监听线程，监听客户端的连接请求
            ServerListenThread serverListenThread = new ServerListenThread(userInfo, serverSocket, systemLog, this);
            serverListenThread.setName("--服务器监听线程--");
            serverListenThread.start();
        } catch (IOException e) {
            systemLog.append("error0");
        }
    }

    public void updateList(UserInfo userInfo) {
        int count = userInfo.getCount();
        onlineUser.clear();
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                Node tempNode = userInfo.searchUserByIndex(i);
                onlineUser.add(tempNode.username);
            }
            onlineUserList.setListData(onlineUser);
        }
        
        String onlineCount = "在线用户" + count + "人";
        onlineCountTextFile.setText(onlineCount);
        onlineUserList.setListData(onlineUser);
    }

    public static void main(String[] args) {
        Server server = new Server("Server");
    }
}
