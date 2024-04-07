import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;

public class ServerReceiveThread extends Thread {
    private Node node;
    private final UserInfo userInfo;
    private final MyStreamSocket myStreamSocket;
    private final StringBuilder systemLog;
    private final Server server;

    public ServerReceiveThread(UserInfo userInfo, Socket socket, StringBuilder systemLog, Server server) throws IOException {
        this.userInfo = userInfo;
        this.myStreamSocket = new MyStreamSocket(socket);
        this.systemLog = systemLog;
        this.server = server;
    }

    public void updateInformation(StringBuilder userList) throws IOException {
        myStreamSocket.sendMessage(String.valueOf(userList));
    }

    @Override
    public void run() {
        Timer timer = new Timer(true);
        Date date = new Date();
        boolean isStop = false;
        try {
            String[] message = myStreamSocket.receiveMessage().split("&");
            node = new Node(message[0], InetAddress.getByName(message[1]), Integer.parseInt(message[2]));
            System.out.println(message[1]);

            userInfo.addUser(node);
            String timeStamp = MyTools.getFormatDate(new Date());
            systemLog.append(timeStamp);
            systemLog.append("用户\"").append(message[0]).append("\"连接成功！\n");
            systemLog.append("当前在线用户有：");
            for (int i = 0; i < userInfo.getCount(); i++) {
                systemLog.append(userInfo.searchUserByIndex(i).username).append(" ");
            }
            systemLog.append("\n");
            System.out.println(systemLog);
            server.onlineMessage = new OnlineOfflineMessage(node);
            userInfo.setOnlineStatus(true);
            node.setOnlineInfo(false);  //不给自己发通知，自己需要更新列表
            server.setSystemLog(systemLog);
            server.updateList(userInfo);
            timer.schedule(new TimerTask() {
                @Override
                public void run() {
                    StringBuilder userList = new StringBuilder();
                    if (node != null && node.isOfflineInfo()) {
                        userList.append("下线通知@@");
                        userList.append(server.offlineMessage.node().toString());
                        node.setOfflineInfo(false);
                        try {
                            updateInformation(userList);
                        } catch (IOException e) {
                            throw new RuntimeException(e);
                        }
                    } else if (node != null && node.isOnlineInfo()) {
                        userList.append("上线通知@@");
                        userList.append(server.onlineMessage.node().toString());
                        node.setOnlineInfo(false);
                        try {
                            updateInformation(userList);
                        } catch (IOException e) {
                            throw new RuntimeException(e);
                        }
                    } else if (node != null && node.isJustOnline()) {
                        userList.append("更新列表@@");
                        userList.append(userInfo.toString());
                        node.setJustOnline(false);
                        try {
                            updateInformation(userList);
                        } catch (IOException e) {
                            throw new RuntimeException(e);
                        }
                    }
                }
            }, date, 1000);
            String msg;
            while (!isStop) {
                msg = myStreamSocket.receiveMessage();
                if ("#".equals(msg)) {
                    myStreamSocket.sendMessage("#@@");
                    userInfo.deleteUser(node);
                    server.updateList(userInfo);
                    String timestamp = MyTools.getFormatDate(new Date());
                    systemLog.append(timestamp);
                    systemLog.append(node.username).append("已下线\n");
                    systemLog.append("当前在线用户有");
                    for (int i = 0; i < userInfo.getCount(); i++) {
                        systemLog.append(userInfo.searchUserByIndex(i).username).append(" ");
                    }
                    server.setSystemLog(systemLog);
                    System.out.println("下线通知：" + node.username);
                    //准备发送给所以在线客户
                    server.offlineMessage = new OnlineOfflineMessage(node);
                    userInfo.setOfflineStatus(true);
                    node = null;
                    myStreamSocket.close();
                    isStop = true;
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
