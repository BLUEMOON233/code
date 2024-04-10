public class TestClient01 {
    public static void main(String[] args) {
        Thread t = new Thread(()->{
            new Client("Client-1");
        });
        t.start();
    }
}
