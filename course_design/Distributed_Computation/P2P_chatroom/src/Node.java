import java.io.Serializable;
import java.net.InetAddress;

public class Node implements Serializable {
    String username = "";
    InetAddress ip;
    int port;

    public Node(String username, InetAddress ip, int port) {
        this.username = username;
        this.ip = ip;
        this.port = port;
//        isOfflineInfo = false;
//        isOnlineInfo = false;
//        isJustOnline = true;
    }
}
