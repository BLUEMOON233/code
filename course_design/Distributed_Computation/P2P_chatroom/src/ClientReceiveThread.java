import java.io.IOException;
import java.net.ServerSocket;
import java.util.Date;

public class ClientReceiveThread extends Thread{
    private final Node node;
    private final int clientListenPort;
    private final Client client;
    public ClientReceiveThread(Node node, Client client) {
        this.node = node;
        this.clientListenPort = node.port;
        this.client = client;
    }

    @Override
    public void run() {
        try {
            ServerSocket serverSocket = new ServerSocket(clientListenPort);
            while (!client.isStop()){
                MyStreamSocket myStreamSocket = new MyStreamSocket(serverSocket.accept());
                String originalMessage = myStreamSocket.receiveMessage();
                System.out.println("原始接收消息"+originalMessage);
                String senderName = originalMessage.split("&")[0];
                String message = originalMessage.split("&")[1];
                String chatRecord = MyTools.getFormatDate(new Date()) +
                        senderName + "--->" + node.username + "：\n" +
                        message;
                client.setChatRecord(chatRecord);
                myStreamSocket.close();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
