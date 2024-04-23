import java.io.IOException;
import java.net.InetAddress;


public class Client {
    private MyStreamSocket myStreamSocket;

    Client() throws IOException {
//        myStreamSocket = new MyStreamSocket(InetAddress.getByName("42.193.107.194"), 1234);
        myStreamSocket = new MyStreamSocket(InetAddress.getByName("127.0.0.1"), 1234);
    }

    public boolean loginCheck(int number, String password) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@checkStudentPassword", "", 0.0));
        myStreamSocket.sendObject(new UndivertedStudent(number, password, "", 0.0));
        UndivertedStudent us = myStreamSocket.receiveObject();
        if(us.number == -2) {
            return us.name.equals("true");
        }
        return false;
    }

    public UndivertedStudent getUndivertedStudent(int number) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@getUS", String.valueOf(number), 0.0));
        return myStreamSocket.receiveObject();
    }

    public String[] getMajorList() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@getMajor", "", 0.0));
        UndivertedStudent us = myStreamSocket.receiveObject();
        return us.name.split("\\+");
    }

    public void modifyUndivertedStudent(UndivertedStudent us) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@modifyUS", "", 0.0));
        myStreamSocket.sendObject(us);
    }
}
