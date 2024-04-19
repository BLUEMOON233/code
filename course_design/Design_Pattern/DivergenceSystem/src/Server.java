import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private ServerSocket serverSocket;

    Server() throws IOException {
        serverSocket = new ServerSocket(1234);
    }

    public void startServer() throws IOException {
        while (true) {
            Socket socket = serverSocket.accept();
            Thread serverHandleThread = new Thread(new ServerHandleThread(socket));
            serverHandleThread.start();
            InetAddress inetAddress = socket.getInetAddress();
            System.out.println("IP address: " + inetAddress.getHostAddress());
        }
    }

    public static void main(String[] args) {
        try {
            Server server = new Server();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

