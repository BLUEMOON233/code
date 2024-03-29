import java.net.InetAddress;

public class Example2ReceiverSender {
    public static void main(String[] args) {
        if(args.length < 4)
            System.out.println("This program requires four command arguments");
        else {
            try{
                InetAddress receiverHost = InetAddress.getByName(args[0]);
                int receiverPort = Integer.parseInt(args[1]);
                int myPort = Integer.parseInt(args[2]);
                String message = args[3];
                MyDatagramSocket mySocket = new MyDatagramSocket(myPort);
                System.out.println(mySocket.receiveMessage());
                mySocket.sendMessage(receiverHost, receiverPort, message);
                mySocket.close();
            }
            catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }
}
