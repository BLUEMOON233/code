import java.io.Serializable;
import java.net.InetAddress;

public class Node implements Serializable {
    String username = "";
    InetAddress ip;
    int port;

    private boolean isOnlineInfo;   //上线通知
    private boolean isOfflineInfo;  //下线通知
    private boolean isJustOnline;  //是否刚上线

    public Node(String username, InetAddress ip, int port) {
        this.username = username;
        this.ip = ip;
        this.port = port;
        isOfflineInfo = false;
        isOnlineInfo = false;
        isJustOnline = true;
    }
    public boolean isOnlineInfo() {
        return isOnlineInfo;
    }
    public void setOnlineInfo(boolean onlineInfo) {
        isOnlineInfo = onlineInfo;
    }
    public boolean isOfflineInfo() {
        return isOfflineInfo;
    }
    public void setOfflineInfo(boolean offlineInfo) {
        isOfflineInfo = offlineInfo;
    }
    public boolean isJustOnline() {
        return isJustOnline;
    }
    public void setJustOnline(boolean justOnline) {
        isJustOnline = justOnline;
    }

    @Override
    public String toString() {
        return username + '&' + ip.toString().substring(1) + '&' + port;
    }
}
