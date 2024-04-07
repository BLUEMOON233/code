public class TestClient01 {
    public static void main(String[] args) {
        Thread thread = new Thread(() -> {
            new Client("Client01");
        });
        thread.start();
    }
}