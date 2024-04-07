public class TestClient02 {
    public static void main(String[] args) {
        Thread thread = new Thread(() -> {
            new Client("Client02");
        });
        thread.start();
    }
}
