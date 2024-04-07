public class Test01 {
    public static void main(String[] args) {
        Thread server = new Thread(()->{
            new Server("Server");
        });
        Thread client1 = new Thread(()->{
            new Client("Client01");
        });
        Thread client2 = new Thread(()->{
            new Client("Client02");
        });
        Thread client3 = new Thread(()->{
            new Client("Client03");
        });
        server.start();
        client1.start();
        client2.start();
        client3.start();
    }
}
