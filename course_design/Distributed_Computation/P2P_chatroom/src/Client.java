import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.util.Date;
import java.util.List;
import java.util.Vector;

public class Client extends JFrame {
    private final StringBuilder chatRecord;       //聊天记录
    private Vector<String> onlinePeople;    //在线用户
    private Node node;                    //用户结点
    private final UserInfo userInfo;            //在线用户列表信息
    private ComWithServer comWithServer;   //和服务器之间通信线程
    private final boolean isStop;         //是否关闭客户端了
    private String userName = "";       //用户名
    //UI对象
    private JTextArea chatRecordTextArea;   //聊天记录组件
    private JTextArea sendMessageTextArea;  //发送消息组件
    private JTextField onlineCountTextFile; //在线人数组件
    private JList<String> onlinePeopleList;         //在线用户组件
    private JTextField userNameTextFile;    //用户名组件
    private JButton sendMessageButton;      //发送消息组件
    private JButton clearMessageButton;     //清空消息组件
    private JButton userLog;                //用户登录组件
    private JButton userExit;               //用户退出组件

    //构造函数
    public Client(String title) throws HeadlessException {
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
        chatRecord = new StringBuilder();
        isStop = false;
        userInfo = new UserInfo();
    }

    public void init(JPanel panel) {
        JLabel label1 = new JLabel("聊天记录");
        label1.setBounds(5, 0, 492, 25);
        panel.add(label1);

        chatRecordTextArea = new JTextArea();
        chatRecordTextArea.setEditable(false);
        chatRecordTextArea.setBackground(Color.LIGHT_GRAY);
        JScrollPane chatRecordScrollPanel = new JScrollPane(chatRecordTextArea);
        chatRecordScrollPanel.setBounds(5, 26, 492, 300);
        chatRecordScrollPanel.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        panel.add(chatRecordScrollPanel);

        sendMessageTextArea = new JTextArea();
        sendMessageTextArea.setBackground(Color.LIGHT_GRAY);
        JScrollPane sendMessageScrollPane = new JScrollPane(sendMessageTextArea);
        sendMessageScrollPane.setBounds(5, 330, 492, 100);
        panel.add(sendMessageScrollPane);

        sendMessageButton = new JButton();
        sendMessageButton.setText("发送");
        sendMessageButton.setEnabled(false);
        sendMessageButton.setBounds(5, 430, 200, 30);
        panel.add(sendMessageButton);

        clearMessageButton = new JButton();
        clearMessageButton.setText("清除");
        clearMessageButton.setEnabled(false);
        clearMessageButton.setBounds(295, 430, 200, 30);
        panel.add(clearMessageButton);

        JLabel label2 = new JLabel("在线列表");
        label2.setBounds(500, 0, 182, 25);
        panel.add(label2);

        onlineCountTextFile = new JTextField();
        onlineCountTextFile.setText("在线用户0人");
        onlineCountTextFile.setBounds(500, 26, 182, 25);
        onlineCountTextFile.setBackground(Color.LIGHT_GRAY);
        onlineCountTextFile.setOpaque(true);
        panel.add(onlineCountTextFile);

        onlinePeople = new Vector<>();
        onlinePeopleList = new JList<>(onlinePeople);
        onlinePeopleList.setBounds(500, 52, 182, 274);
        onlinePeopleList.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        onlinePeopleList.setBackground(Color.lightGray);
        panel.add(onlinePeopleList);

        JLabel label3 = new JLabel("用户名：");
        label3.setBounds(500, 330, 182, 32);
        panel.add(label3);

        userNameTextFile = new JTextField();
        userNameTextFile.setText(userName);
        userNameTextFile.setBounds(500, 365, 182, 32);
        userNameTextFile.setBackground(Color.LIGHT_GRAY);
        panel.add(userNameTextFile);

        userLog = new JButton();
        userLog.setText("登录");
        userLog.setBounds(500, 399, 182, 30);
        panel.add(userLog);

        userExit = new JButton();
        userExit.setText("退出");
        userExit.setEnabled(false);
        userExit.setBounds(500, 430, 182, 30);
        panel.add(userExit);
    }

    public void eventListener() {
        //发送消息
        sendMessageButton.addActionListener(e -> {
            try {
                sendMessage();
            } catch (Exception ex) {
                setChatRecord(ex.getMessage() + "\n");
            }
        });

        //清空消息
        clearMessageButton.addActionListener(e -> sendMessageTextArea.setText(null));

        //登录
        userLog.addActionListener(e -> {
            try {
                if (!userNameTextFile.getText().isEmpty()) {
                    login();
                }
            } catch (IOException ex) {
                setChatRecord("用户名不能为空");
            }
        });

        //退出
        userExit.addActionListener(e -> {
            try {
                comWithServer.sendEndMessage();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
            System.exit(0);
        });
    }

    public void setChatRecord(String chatRecord) {
        this.chatRecord.append(chatRecord).append("\n");
        chatRecordTextArea.setText(String.valueOf(this.chatRecord));
    }

    public void setChatRecord(StringBuilder chatRecord) {
        chatRecordTextArea.setText(String.valueOf(chatRecord));
    }

    public String getUserName() {
        userName = userNameTextFile.getText().trim();
        return userName;
    }

    public boolean isStop() {
        return isStop;
    }

    public void login() throws IOException {
        String localhost = InetAddress.getLocalHost().getHostAddress();
        int myReceivePort = MyTools.getRandomPort();
        System.out.println("receivePort--->" + myReceivePort);

        node = new Node(getUserName(), InetAddress.getByName(localhost), myReceivePort);
        comWithServer = new ComWithServer(node, userInfo, this);
        comWithServer.start();

        sendMessageButton.setEnabled(true);
        clearMessageButton.setEnabled(true);
        userExit.setEnabled(true);
        userLog.setEnabled(false);
        userNameTextFile.setEditable(false);

        ClientReceiveThread clientReceiveThread = new ClientReceiveThread(node, this);
        clientReceiveThread.setName("--" + node.username + "的接收线程--");
        clientReceiveThread.setDaemon(true);
        clientReceiveThread.start();
    }

    public void sendMessage() throws Exception {
        String sendMsg = sendMessageTextArea.getText();
        System.out.println("输入内容：" + sendMsg);
        if (sendMsg.isEmpty())
            throw new Exception("消息不能为空!");
        List<String> selectedName = onlinePeopleList.getSelectedValuesList();
        ClientSendThread clientSendThread = new ClientSendThread(selectedName, userInfo, node.username, sendMsg);
        clientSendThread.start();
        StringBuilder totalSelected = new StringBuilder();
        for (String name : selectedName)
            totalSelected.append(name).append("、");
        chatRecord.append(MyTools.getFormatDate(new Date()));
        chatRecord.append(node.username).append("--->").append(totalSelected.deleteCharAt(totalSelected.length() - 1)).append("\n");
        chatRecord.append(sendMsg).append("\n");
        setChatRecord(chatRecord);
        sendMessageTextArea.setText(null);
    }

    public void updateList(UserInfo userInfo) {
        int count = userInfo.getCount();
        onlinePeople.clear();
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                Node tempNode = userInfo.searchUserByIndex(i);
                onlinePeople.add(tempNode.username);
            }
            onlinePeopleList.setListData(onlinePeople);
        }
        String onlineCount = "在线用户" + count + "人";
        onlineCountTextFile.setText(onlineCount);
    }

    public static void main(String[] args) {
        Client client = new Client("Client");
    }
}