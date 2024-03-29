import java.io.*;
import java.net.*;

public class DaytimeClient {
    public static void main(String[] args) {
        InputStreamReader inputStreamReader = new InputStreamReader(System.in);
        BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
        try {
            System.out.println("Welcome to the Daytime client.\n" + "What is the name of the server host?");
            String hostName = bufferedReader.readLine();
            if(hostName.length() == 0)
                hostName = "localhost";
            System.out.println("What is the port number of the server host?");
            String portNum = bufferedReader.readLine();
            if(portNum.length() == 0)
                portNum = "13";
            System.out.println("Here is the timestamp received from the server"
                    + DaytimeClientHelper.getTimestamp(hostName, portNum));
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}

class DaytimeClientHelper {
    public static String getTimestamp(String hostName, String portNum) throws Exception {
        String timestamp = "";
        InetAddress serverHost = InetAddress.getByName(hostName);
        int serverPort = Integer.parseInt(portNum);
        System.out.println("Connection request made");
        MyStreamSocket mySocket = new MyStreamSocket(serverHost, serverPort);
        timestamp = mySocket.ReceiveMessage();
        mySocket.close();
        return timestamp;
    }
}