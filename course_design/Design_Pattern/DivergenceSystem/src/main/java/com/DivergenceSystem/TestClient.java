package com.DivergenceSystem;

import java.io.IOException;
import java.net.Socket;

public class TestClient {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("42.193.107.194", 1234);
//        Socket socket = new Socket("localhost", 1234);
        MyStreamSocket myStreamSocket = new MyStreamSocket(socket);
        UndivertedStudent op = new UndivertedStudent(-2, "-singleUS", "", 0);
        UndivertedStudent us = new UndivertedStudent(2021902610, "刘文越", "男", 90);
        UndivertedStudent exit = new UndivertedStudent(-2, "exit", "", 0);
        myStreamSocket.sendObject(op);
        myStreamSocket.sendObject(us);
        myStreamSocket.sendObject(exit);
    }
}
