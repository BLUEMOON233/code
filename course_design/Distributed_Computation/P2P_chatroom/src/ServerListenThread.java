import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerListenThread extends Thread{
    private final UserInfo userInfo;
    private final ServerSocket serverSocket;
    private final StringBuilder systemLog;
    private final Server server;
    public ServerListenThread(UserInfo userInfo, ServerSocket serverSocket, StringBuilder systemLog, Server server) {
        this.userInfo = userInfo;
        this.serverSocket = serverSocket;
        this.systemLog = systemLog;
        this.server = server;
    }

    @Override
    public void run() {
        try {
            while (!server.isStop()){
                Socket socket = serverSocket.accept();
                ServerReceiveThread serverReceiveThread = new ServerReceiveThread(userInfo,socket,systemLog,server);
                String name = socket.getInetAddress().getHostAddress();
                serverReceiveThread.setName("--服务器与"+name+"连接线程--");
                serverReceiveThread.start();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
