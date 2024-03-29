import java.net.*;
import java.util.Date;

public class DaytimeServer {
    public static void main(String[] args) {
        int serverPort = 13;
        if(args.length == 1)
            serverPort = Integer.parseInt(args[0]);
        try{
            ServerSocket myConnectionSocket = new ServerSocket(serverPort);
            System.out.println("Daytime Server Ready.");
            while(true) {
                System.out.println("Waiting for a connection");
                MyStreamSocket myStreamSocket = new MyStreamSocket(myConnectionSocket.accept());
                System.out.println("A client has made connection");
                Date timestamp = new Date();
                System.out.println("timestamp sent: " + timestamp.toString());
                myStreamSocket.sendMessage(timestamp.toString());
                myStreamSocket.close();
            }
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
