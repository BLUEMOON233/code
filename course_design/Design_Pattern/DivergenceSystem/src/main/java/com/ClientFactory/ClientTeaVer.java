package com.ClientFactory;

import com.DivergenceSystem.MyStreamSocket;
import com.DivergenceSystem.ProcessedStudent;
import com.DivergenceSystem.UndivertedStudent;

import java.io.IOException;
import java.net.InetAddress;
import java.util.ArrayList;
import java.util.List;

public class ClientTeaVer implements Client{
    private MyStreamSocket myStreamSocket;

    ClientTeaVer() throws IOException {
        myStreamSocket = new MyStreamSocket(InetAddress.getByName("42.193.107.194"), 1234);
//        myStreamSocket = new MyStreamSocket(InetAddress.getByName("localhost"), 1234);
    }

    @Override
    public boolean loginCheck(int number, String password) {
        return false;
    }

    @Override
    public boolean adminLoginCheck(int number, String password) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@checkAdminPassword", "", 0.0));
        myStreamSocket.sendObject(new UndivertedStudent(number, password, "", 0.0));
        UndivertedStudent us = myStreamSocket.receiveObject();
        if (us.number == -2) {
            return us.name.equals("true");
        }
        return false;
    }

    @Override
    public UndivertedStudent getUndivertedStudent(int number) {
        return null;
    }

    @Override
    public List<UndivertedStudent> getUSList() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@getUSList", "", 0.0));
        int flag = 0;
        List<UndivertedStudent> ret = new ArrayList<UndivertedStudent>();
        while (flag != -1) {
            UndivertedStudent us = myStreamSocket.receiveObject();
            if (us.number != -1) ret.add(us);
            flag = us.number;
        }
        return ret;
    }

    @Override
    public void addUSList(List<UndivertedStudent> usList) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@addUSList", "", 0.0));
        for (UndivertedStudent us : usList) {
            myStreamSocket.sendObject(us);
        }
        myStreamSocket.sendObject(new UndivertedStudent(-1, "end", "", 0.0));
    }

    @Override
    public void modifyUndivertedStudent(UndivertedStudent us) {

    }

    @Override
    public List<UndivertedStudent> getMajorClass() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@getMajorClass", "", 0.0));
        int flag = 0;
        List<UndivertedStudent> ret = new ArrayList<UndivertedStudent>();
        while (flag != -2) {
            UndivertedStudent us = myStreamSocket.receiveObject();
            if (us.number != -2) ret.add(us);
            flag = us.number;
        }
        return ret;
    }

    @Override
    public void addMajor(String majorName) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@addMajor", majorName, 0.0));
    }

    @Override
    public void delMajor(int code) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@delMajor", String.valueOf(code), 0.0));
    }

    @Override
    public void modifyMajor(int code, int class_number) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@modifyMajor", String.valueOf(code) + '&' + String.valueOf(class_number), 0.0));
    }

    @Override
    public void initClass() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@initClass", "", 0.0));
    }


    @Override
    public void modifyClass(List<UndivertedStudent> classNums) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@modifyClassNumber", "", 0.0));
        for (UndivertedStudent us : classNums) {
            myStreamSocket.sendObject(us);
        }
        myStreamSocket.sendObject(new UndivertedStudent(-1, "end", "", 0.0));
    }


    @Override
    public List<UndivertedStudent> getClassList() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@getClassList", "", 0.0));
        int flag = 0;
        List<UndivertedStudent> ret = new ArrayList<UndivertedStudent>();
        while (flag != -1) {
            UndivertedStudent us = myStreamSocket.receiveObject();
            if (us.number != -1) ret.add(us);
            flag = us.number;
        }
        return ret;
    }

    @Override
    public void clearStuInfoWithFill() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@clearStuInfoWithFill", "", 0.0));
    }

    @Override
    public void clearStuInfoProcessed() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@clearStuInfoProcessed", "", 0.0));
    }

    @Override
    public List<ProcessedStudent> getPSList() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@getPSList", "", 0.0));
        int flag = 0;
        List<ProcessedStudent> ret = new ArrayList<>();
        while (flag != -1) {
            ProcessedStudent us = myStreamSocket.receivePSObject();
            if (us.number != -1) ret.add(us);
            flag = us.number;
        }
        return ret;
    }

    @Override
    public void diverge() {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@diverge", "", 0.0));
    }
}
