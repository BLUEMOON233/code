import java.io.IOException;
import java.net.Socket;
import java.util.List;

public class ServerHandleThread implements Runnable {
    Socket socket;
    DatabaseOperator serverDO;
    MyStreamSocket myStreamSocket;
    boolean isStop = false;

    public ServerHandleThread(Socket socket, DatabaseOperator serverDO) throws IOException {
        super();
        this.socket = socket;
        this.serverDO = serverDO;
        myStreamSocket = new MyStreamSocket(this.socket);
    }


    @Override
    public void run() {
        while (!isStop) {
            UndivertedStudent op = myStreamSocket.receiveObject();
            if (op.number != -2)
                continue;
            switch (op.name) {
                case "#exit" -> {
                    isStop = true;
                }
                case "+singleUS" -> {
                    UndivertedStudent us = myStreamSocket.receiveObject();
                    serverDO.addUndivertedStudent(us);
                }
                case "-singleUS" -> {
                    UndivertedStudent us = myStreamSocket.receiveObject();
                    serverDO.delUndivertedStudent(us.number);
                }
                case "@checkStudentPassword" -> {
                    UndivertedStudent us = myStreamSocket.receiveObject();
                    String password = serverDO.queryStudentPassword(us.number);
                    UndivertedStudent ret = new UndivertedStudent(-2, (password.equals(us.name)) ? "true" : "false", "", 0.0);
                    myStreamSocket.sendObject(ret);
                }
                case "@checkAdminPassword" -> {
                    UndivertedStudent us = myStreamSocket.receiveObject();
                    String password = serverDO.queryAdminPassword(us.number);
                    UndivertedStudent ret = new UndivertedStudent(-2, (password.equals(us.name)) ? "true" : "false", "", 0.0);
                    myStreamSocket.sendObject(ret);
                }
                case "@getUS" -> {
                    UndivertedStudent ret = serverDO.getUndivertedStudent(Integer.parseInt(op.gender));
                    myStreamSocket.sendObject(ret);
                }
                case "@getMajor" -> {
                    String sendMessage = serverDO.queryMajor();
                    myStreamSocket.sendObject(new UndivertedStudent(-2, sendMessage, "", 0.0));
                }
                case "@getMajorClass" -> {
                    List<UndivertedStudent> majorList = serverDO.getMajorClass();
                    for(UndivertedStudent major : majorList) {
                        myStreamSocket.sendObject(major);
                    }
                    myStreamSocket.sendObject(new UndivertedStudent(-1, "end", "", 0.0));
                }
                case "@modifyUS" -> {
                    UndivertedStudent us = myStreamSocket.receiveObject();
                    serverDO.modifyUndivertedStudent(us);
                }
            }
        }
        try {
            myStreamSocket.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}