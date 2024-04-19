import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;

public class MyStreamSocket extends Socket {
    private Socket socket;
    private ObjectInputStream ois;
    private ObjectOutputStream oos;

    MyStreamSocket(InetAddress acceptorHost, int acceptorPort)
            throws SocketException, IOException {
        socket = new Socket(acceptorHost, acceptorPort);
        setStreams();
    }

    MyStreamSocket(Socket socket) throws IOException {
        this.socket = socket;
        setStreams();
    }

    private void setStreams() throws IOException {
        InputStream inputStream = socket.getInputStream();
        ois = new ObjectInputStream(inputStream);
        OutputStream outputStream = socket.getOutputStream();
        oos = new ObjectOutputStream(outputStream);
    }

    public void sendObject(UndivertedStudent us) {
        try {
            oos.writeObject(us);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public UndivertedStudent receiveObject() {
        try {
            return (UndivertedStudent) ois.readObject();
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}
