public class TestClient02 {
    public static void main(String[] args) {
        Thread t = new Thread(()->{
            new Client("Client-2");
        });
        t.start();
        Thread t1 = new Thread(()->{
            new Client("Client-3");
        });
        t1.start();
    }
}
