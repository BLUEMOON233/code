package com.ClientFactory;

import com.DivergenceSystem.*;

import java.util.List;

public interface Client {
    public boolean loginCheck(int number, String password);

    public boolean adminLoginCheck(int number, String password);

    public UndivertedStudent getUndivertedStudent(int number);

    public List<UndivertedStudent> getUSList();

    public void addUSList(List<UndivertedStudent> usList);

    public void modifyUndivertedStudent(UndivertedStudent us);

    public List<UndivertedStudent> getMajorClass();

    public void addMajor(String majorName);

    public void delMajor(int code);

    public void modifyMajor(int code, int class_number);

    public void initClass();

    public void modifyClass(List<UndivertedStudent> classNums);

    public List<UndivertedStudent> getClassList();

    public void clearStuInfoWithFill();

    public void clearStuInfoProcessed();

    public List<ProcessedStudent> getPSList();

    public void diverge();

}
