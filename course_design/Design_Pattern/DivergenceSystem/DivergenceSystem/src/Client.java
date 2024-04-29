import java.io.IOException;
import java.net.InetAddress;
import java.util.ArrayList;
import java.util.List;


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
        if (us.number == -2) {
            return us.name.equals("true");
        }
        return false;
    }

    public boolean adminLoginCheck(int number, String password) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@checkAdminPassword", "", 0.0));
        myStreamSocket.sendObject(new UndivertedStudent(number, password, "", 0.0));
        UndivertedStudent us = myStreamSocket.receiveObject();
        if (us.number == -2) {
            return us.name.equals("true");
        }
        return false;
    }

    public UndivertedStudent getUndivertedStudent(int number) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@getUS", String.valueOf(number), 0.0));
        return myStreamSocket.receiveObject();
    }

    public List<UndivertedStudent> getUSList() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@getUSList", "", 0.0));
        int flag = 0;
        List<UndivertedStudent> ret = new ArrayList<UndivertedStudent>();
        while (flag != -1) {
            UndivertedStudent us = myStreamSocket.receiveObject();
            if (us.number != -1) ret.add(us);
            flag = us.number;
        }
        return ret;
    }

    public void addUSList(List<UndivertedStudent> usList) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "+addUSList", "", 0.0));
        for (UndivertedStudent us : usList) {
            myStreamSocket.sendObject(us);
        }
        myStreamSocket.sendObject(new UndivertedStudent(-1, "end", "", 0.0));
    }

    public void modifyUndivertedStudent(UndivertedStudent us) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@modifyUS", "", 0.0));
        myStreamSocket.sendObject(us);
    }

    public List<UndivertedStudent> getMajorClass() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@getMajorClass", "", 0.0));
        int flag = 0;
        List<UndivertedStudent> ret = new ArrayList<UndivertedStudent>();
        while (flag != -1) {
            UndivertedStudent us = myStreamSocket.receiveObject();
            if (us.number != -1) ret.add(us);
            flag = us.number;
        }
        return ret;
    }

    public void addMajor(String majorName) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "+addMajor", majorName, 0.0));
    }

    public void delMajor(int code) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "-delMajor", String.valueOf(code), 0.0));
    }

    public void modifyMajor(int code, int class_number) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@modifyMajor", String.valueOf(code) + '&' + String.valueOf(class_number), 0.0));
    }

    public void initClass() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@initClass", "", 0.0));
    }

    public void saveClass(List<UndivertedStudent> classNums) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@modifyClassNumber", "", 0.0));
        for (UndivertedStudent us : classNums) {
            myStreamSocket.sendObject(us);
        }
        myStreamSocket.sendObject(new UndivertedStudent(-1, "end", "", 0.0));
    }

    public List<UndivertedStudent> getClassList() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@getClassList", "", 0.0));
        int flag = 0;
        List<UndivertedStudent> ret = new ArrayList<UndivertedStudent>();
        while (flag != -1) {
            UndivertedStudent us = myStreamSocket.receiveObject();
            if (us.number != -1) ret.add(us);
            flag = us.number;
        }
        return ret;
    }

    public void clearStuInfoWithFill() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "-clearStuInfoWithFill", "", 0.0));
    }

    public void diverge() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@diverge", "", 0.0));
    }

    public void clearStuInfoProcessed() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "-clearStuInfoProcessed", "", 0.0));
    }

    public List<ProcessedStudent> getPSList() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@getPSList", "", 0.0));
        int flag = 0;
        List<ProcessedStudent> ret = new ArrayList<>();
        while (flag != -1) {
            ProcessedStudent us = myStreamSocket.receivePSObject();
            if (us.number != -1) ret.add(us);
            flag = us.number;
        }
        return ret;
    }
}
