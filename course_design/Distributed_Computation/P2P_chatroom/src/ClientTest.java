public class ClientTest {
    public static void main(String[] args) {
        Thread thread = new Thread(() -> {
            new Client("P2PChat客户端1");
        });
        thread.start();
    }
}
