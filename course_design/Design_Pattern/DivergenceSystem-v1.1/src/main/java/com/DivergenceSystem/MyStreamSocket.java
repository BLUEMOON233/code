package com.DivergenceSystem;

import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;

public class MyStreamSocket extends Socket {
    private Socket socket;
    private ObjectInputStream ois;
    private ObjectOutputStream oos;

    public MyStreamSocket(InetAddress acceptorHost, int acceptorPort)
            throws IOException {
        socket = new Socket(acceptorHost, acceptorPort);
        setStreams();
    }

    MyStreamSocket(Socket socket) throws IOException {
        this.socket = socket;
        setStreams();
    }

    private void setStreams(){
        InputStream inputStream = null;
        try {
            OutputStream outputStream = socket.getOutputStream();
            oos = new ObjectOutputStream(outputStream);
            inputStream = socket.getInputStream();
            ois = new ObjectInputStream(inputStream);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void sendObject(UndivertedStudent us) {
        try {
            oos.writeObject(us);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public UndivertedStudent receiveObject() {
        try {
            return (UndivertedStudent) ois.readObject();
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public void sendObject(ProcessedStudent us) {
        try {
            oos.writeObject(us);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public ProcessedStudent receivePSObject() {
        try {
            return (ProcessedStudent) ois.readObject();
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}
