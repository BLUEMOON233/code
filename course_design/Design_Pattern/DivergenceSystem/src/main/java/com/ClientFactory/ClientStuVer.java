package com.ClientFactory;

import com.DivergenceSystem.MyStreamSocket;
import com.DivergenceSystem.ProcessedStudent;
import com.DivergenceSystem.UndivertedStudent;

import java.io.IOException;
import java.net.InetAddress;
import java.util.ArrayList;
import java.util.List;

public class ClientStuVer implements Client{
    private MyStreamSocket myStreamSocket;

    ClientStuVer() throws IOException {
        myStreamSocket = new MyStreamSocket(InetAddress.getByName("127.0.0.1"), 1234);
    }

    @Override
    public boolean loginCheck(int number, String password) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@checkStudentPassword", "", 0.0));
        myStreamSocket.sendObject(new UndivertedStudent(number, password, "", 0.0));
        UndivertedStudent us = myStreamSocket.receiveObject();
        if (us.number == -2) {
            return us.name.equals("true");
        }
        return false;
    }

    @Override
    public boolean adminLoginCheck(int number, String password) {
        return false;
    }

    @Override
    public UndivertedStudent getUndivertedStudent(int number) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@getUS", String.valueOf(number), 0.0));
        return myStreamSocket.receiveObject();
    }
    @Override
    public List<UndivertedStudent> getUSList() {
        return null;
    }

    @Override
    public void addUSList(List<UndivertedStudent> usList) {

    }

    @Override
    public void modifyUndivertedStudent(UndivertedStudent us) {
        myStreamSocket.sendObject(new UndivertedStudent(-2, "@modifyUS", "", 0.0));
        myStreamSocket.sendObject(us);
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

    }

    @Override
    public void delMajor(int code) {

    }

    @Override
    public void modifyMajor(int code, int class_number) {

    }

    @Override
    public void initClass() {

    }

    @Override
    public void modifyClass(List<UndivertedStudent> classNums) {

    }

    @Override
    public List<UndivertedStudent> getClassList() {
        return null;
    }

    @Override
    public void clearStuInfoWithFill() {

    }

    @Override
    public void clearStuInfoProcessed() {

    }

    @Override
    public List<ProcessedStudent> getPSList() {
        return null;
    }

    @Override
    public void diverge() {

    }
}
