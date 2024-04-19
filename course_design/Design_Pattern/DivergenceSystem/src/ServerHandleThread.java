import java.net.Socket;

public class ServerHandleThread implements Runnable {
    Socket socket;
    public ServerHandleThread(Socket socket) {
        super();
        this.socket = socket;
    }


    @Override
    public void run() {

    }
}