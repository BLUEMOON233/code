import java.io.IOException;
import java.net.Socket;
import java.util.List;

public class ClientSendThread extends Thread {
    private final List<String> selectedName;
    private final UserInfo userInfo;
    private final String myName;
    private final String message;

    public ClientSendThread(List<String> selectedName, UserInfo userInfo, String name, String message) {
        this.selectedName = selectedName;
        this.userInfo = userInfo;
        this.myName = name;
        this.message = message;
    }

    @Override
    public void run() {
        try {
            for (String name : selectedName) {
                Node acceptorNode = userInfo.searchUserByName(name);
                Socket socket = new Socket(acceptorNode.ip, acceptorNode.port);
                MyStreamSocket myStreamSocket = new MyStreamSocket(socket);
                myStreamSocket.sendMessage(myName + "&" + message);
                myStreamSocket.close();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
