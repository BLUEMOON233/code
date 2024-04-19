import java.io.IOException;
import java.net.Socket;

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
        while(!isStop) {
            UndivertedStudent op = myStreamSocket.receiveObject();
            if(op.number != -2)
                continue;
            switch (op.name) {
                case "exit" ->{
                    isStop = true;
                }
                case "+singleUS" ->{
                    UndivertedStudent us = myStreamSocket.receiveObject();
                    serverDO.addUndivertedStudent(us);
                }
                case  "-singleUS" ->{
                    UndivertedStudent us = myStreamSocket.receiveObject();
                    serverDO.delUndivertedStudent(us.number);
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