import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;

public class MyStreamSocket extends Socket {
    private Socket socket;
    private BufferedReader input;
    private PrintWriter output;
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
        input = new BufferedReader(new InputStreamReader(inputStream));
        OutputStream outputStream = socket.getOutputStream();
        output = new PrintWriter((new OutputStreamWriter(outputStream)));
    }

    public void sendMessage(String message) throws IOException {
        output.println(message);
        output.flush();
    }

    public String receiveMessage() throws IOException {
        String message = input.readLine();
        return message;
    }
}
