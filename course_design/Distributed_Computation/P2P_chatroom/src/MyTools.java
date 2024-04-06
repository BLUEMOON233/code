import java.io.IOException;
import java.net.ServerSocket;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;

public class MyTools {
    public static String getFormatDate(Date date){
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("HH:mm:ss");
        return "【"+simpleDateFormat.format(date)+"】";
    }

    public static int getRandomPort() {
        Random random = new Random();
        while (true){
            try {
                int port = random.nextInt(65535);
                ServerSocket socket = new ServerSocket(port);
                socket.close();
                return port;
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
