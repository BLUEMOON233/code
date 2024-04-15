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
            server.setSystemLog(systemLog);
            server.updateList(userInfo);
//            System.out.println(systemLog);
            server.onlineMessage = new OnlineOfflineMessage(node);
            userInfo.setOnlineStatus(true); //需要告知所有Node上线
            node.setOnlineInfo(false); //不需要给自己发上线通知

            timer.schedule(new TimerTask() {
                @Override
                public void run() {
                    if (node != null) {
                        StringBuilder userList = new StringBuilder();
                        if (node.isOfflineInfo()) {
                            userList.append("UserLogout@@");
                            userList.append(server.offlineMessage.node().toString());
                            node.setOfflineInfo(false);
                            try {
                                updateInformation(userList);
                            } catch (IOException e) {
                                throw new RuntimeException(e);
                            }
                        } else if (node.isOnlineInfo()) {
                            userList.append("UserLogin@@");
                            userList.append(server.onlineMessage.node().toString());
                            node.setOnlineInfo(false);
                            try {
                                updateInformation(userList);
                            } catch (IOException e) {
                                throw new RuntimeException(e);
                            }
                        } else if (node.isJustOnline()) {
                            userList.append("Initialization@@");
                            userList.append(userInfo.toString());
                            node.setJustOnline(false);
                            try {
                                updateInformation(userList);
                            } catch (IOException e) {
                                throw new RuntimeException(e);
                            }
                        }
                    }
                }
            }, date, 1000);

            String endMessage;
            while (!isStop) {
                endMessage = myStreamSocket.receiveMessage();
                if ("#".equals(endMessage)) {
                    myStreamSocket.sendMessage("#@@");
                    userInfo.deleteUser(node);
                    server.updateList(userInfo);

                    systemLog.append(MyTools.getFormatDate(new Date()));
                    systemLog.append(node.username).append("已下线\n");
                    systemLog.append("当前在线用户有");
                    for (int i = 0; i < userInfo.getCount(); i++) {
                        systemLog.append(userInfo.searchUserByIndex(i).username).append(" ");
                    }
                    systemLog.append("\n");
                    server.setSystemLog(systemLog);
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
