package com.DivergenceSystem;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.Scanner;

public class Server {
    private ServerSocket serverSocket;
    private DatabaseOperator serverDO;
    private boolean isStop = false;

    public Server() throws IOException {
        serverSocket = new ServerSocket(1234);
        serverDO = new DatabaseOperator();
    }

    public void startServer() {
        while (!isStop) {
            Socket socket = null;
            Thread serverHandleThread = null;
            try {
                socket = serverSocket.accept();
                serverHandleThread = new Thread(new ServerHandleThread(socket, serverDO));
                serverHandleThread.start();
                InetAddress inetAddress = socket.getInetAddress();
                System.out.println("New Client's IP address: " + inetAddress.getHostAddress());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public void closeServer() {
        isStop = true;
    }


    public static void main(String[] args) {
        Server server = null;
        try {
            server = new Server();
            server.startServer();
//            server.closeServer();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

