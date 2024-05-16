import java.io.IOException;
import java.net.Socket;
import java.util.ArrayList;
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
                // loginCheck:
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
                // US: [add del query modify]
                case "@getUS" -> {
                    UndivertedStudent ret = serverDO.getUndivertedStudent(Integer.parseInt(op.gender));
                    myStreamSocket.sendObject(ret);
                }
                case "@getUSList" -> {
                    List<UndivertedStudent> list = serverDO.getUSList();
                    for(UndivertedStudent us : list) {
                        myStreamSocket.sendObject(us);
                    }
                    myStreamSocket.sendObject(new UndivertedStudent(-1, "end", "", 0.0));
                }
                case "@addUSList" -> {
                    int flag = 0;
                    List<UndivertedStudent> usList = new ArrayList<UndivertedStudent>();
                    while(flag != -1) {
                        UndivertedStudent us = myStreamSocket.receiveObject();
                        if(us.number != -1) usList.add(us);
                        flag = us.number;
                    }
                    serverDO.addUSList(usList);
                }
                case "@modifyUS" -> {
                    UndivertedStudent us = myStreamSocket.receiveObject();
                    serverDO.modifyUndivertedStudent(us);
                }
                //major table: [add del query modify]
                case "@getMajorClass" -> {
                    List<UndivertedStudent> majorList = serverDO.getMajorClass();
                    for(UndivertedStudent major : majorList) {
                        myStreamSocket.sendObject(major);
                    }
                    myStreamSocket.sendObject(new UndivertedStudent(-2, "end", "", 0.0));
                }
                case "@addMajor" -> {
                    System.out.println(op);
                    serverDO.addMajor(op.gender);
                }
                case "@delMajor" -> {
                    serverDO.delMajor(Integer.parseInt(op.gender));
                }
                case "@modifyMajor" -> {
                    String[] value = op.gender.split("&");
                    int code = Integer.parseInt(value[0]), class_number = Integer.parseInt(value[1]);
                    serverDO.modifyMajor(code, class_number);
                }
                //class table: [add del query modify]
                case "@initClass" -> {
                    serverDO.initClass();
                }
                case "@modifyClassNumber" -> {
                    int flag = 0;
                    List<UndivertedStudent> classNums = new ArrayList<UndivertedStudent>();
                    while(flag != -1) {
                        UndivertedStudent us = myStreamSocket.receiveObject();
                        if(us.number != -1) classNums.add(us);
                        flag = us.number;
                    }
                    serverDO.modifyClassNumber(classNums);
                }
                case "@getClassList" -> {
                    List<UndivertedStudent> classList = serverDO.getClassList();
                    for(UndivertedStudent singleClass : classList) {
                        myStreamSocket.sendObject(singleClass);
                    }
                    myStreamSocket.sendObject(new UndivertedStudent(-1, "end", "", 0.0));
                }
                // StuInfoWithFill table
                case "@clearStuInfoWithFill" -> {
                    serverDO.clearStuInfoWithFill();;
                }
                // StuInfoProcessed table
                case "@clearStuInfoProcessed" -> {
                    serverDO.clearStuInfoProcessed();
                }
                case "@getPSList" -> {
                    List<ProcessedStudent> psList = serverDO.getPSList();
                    for(ProcessedStudent ps : psList) {
                        myStreamSocket.sendObject(ps);
                    }
                    myStreamSocket.sendObject(new ProcessedStudent(-1, "end", "", 0.0, ""));
                }

                case "@diverge" -> {
                    serverDO.diverge();
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