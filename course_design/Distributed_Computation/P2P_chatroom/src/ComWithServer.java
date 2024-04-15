import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Date;

public class ComWithServer extends Thread {
    private final Node node;
    private final UserInfo userInfo;
    private final Client client;
    private MyStreamSocket myStreamSocket;
    private boolean isStop = true;


    ComWithServer(Node node, UserInfo userInfo, Client client) {
        this.node = node;
        this.userInfo = userInfo;
        this.client = client;
        this.isStop = false;
    }

    public void sendEndMessage() throws IOException {
        myStreamSocket.sendMessage("#");
        myStreamSocket.close();
        this.isStop = true;
//        System.out.println("我自己下线通知："+node);
    }

    @Override
    public void run() {
        try {
            Socket socket = new Socket("localhost", 1234);
            myStreamSocket = new MyStreamSocket(socket);
            myStreamSocket.sendMessage(node.toString());
            client.setChatRecord(MyTools.getFormatDate(new Date()) + node.username + "与服务器连接成功！");
            while (!isStop) {
                String originalMessage = myStreamSocket.receiveMessage();
                System.out.println(originalMessage);
                String[] userList = originalMessage.split("@@");
                switch (userList[0]) {
                    case "UserLogin" -> {
                        String[] onlineUserInfo = userList[1].split("&");
                        String onlineUserName = onlineUserInfo[0];
                        InetAddress onlineUserIP = InetAddress.getByName(onlineUserInfo[1]);
                        int onlineUserListenPort = Integer.parseInt(onlineUserInfo[2]);
                        Node tempNode = new Node(onlineUserName, onlineUserIP, onlineUserListenPort);
                        userInfo.addUser(tempNode);
                        client.updateList(userInfo);
                        System.out.println("上线通知：" + node);
                        client.setChatRecord(MyTools.getFormatDate(new Date()) + onlineUserName + "已上线！");

                    }
                    case "UserLogout" -> {
                        String[] offlineUserInfo = userList[1].split("&");
                        String offlineUserName = offlineUserInfo[0];
                        InetAddress offlineUserIP = InetAddress.getByName(offlineUserInfo[1]);
                        int offlineUserListenPort = Integer.parseInt(offlineUserInfo[2]);
                        Node tempNode = new Node(offlineUserName, offlineUserIP, offlineUserListenPort);
                        userInfo.deleteUser(offlineUserName);
                        client.updateList(userInfo);
                        System.out.println("下线通知："+node);
                        client.setChatRecord(MyTools.getFormatDate(new Date())+offlineUserName + "已下线！");
                    }
                    case "Initialization" -> {
                        String[] originalUserInfo = userList[1].split("\\$");
                        for (String node_string : originalUserInfo) {
                            String[] onlineUserInfo = node_string.split("&");
                            String onlineUserName = onlineUserInfo[0];
                            InetAddress onlineUserIP = InetAddress.getByName(onlineUserInfo[1]);
                            int onlineUserListenPort = Integer.parseInt(onlineUserInfo[2]);
                            Node tempNode = new Node(onlineUserName, onlineUserIP, onlineUserListenPort);
                            userInfo.addUser(tempNode);
                        }
                        client.updateList(userInfo);
                        System.out.println("更新列表："+userInfo);
                    }
                }
            }

        } catch (Exception e) {
            throw new RuntimeException(e);
        }

    }


}
