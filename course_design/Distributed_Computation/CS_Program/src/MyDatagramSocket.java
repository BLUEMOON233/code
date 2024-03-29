import java.net.*;
import java.io.*;
import java.nio.Buffer;

public class MyDatagramSocket extends DatagramSocket{
    static final int MAX_LEN = 100;
    MyDatagramSocket(int portNo) throws SocketException {
        super(portNo);
    }
    public void sendMessage(InetAddress receiverHost, int receiverPort, String message)
        throws IOException {
        byte[] sendBuffer = message.getBytes();
        DatagramPacket datagram =
                new DatagramPacket(sendBuffer, sendBuffer.length, receiverHost, receiverPort);
        this.send(datagram);
    }

    public String receiveMessage()
        throws IOException{
        byte[] receiverBuffer = new byte[MAX_LEN];
        DatagramPacket datagram =
                new DatagramPacket(receiverBuffer, MAX_LEN);
        this.receive(datagram);
        String message = new String(receiverBuffer);
        return message;
    }
}
