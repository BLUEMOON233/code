import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TestWRProblem {
    boolean isReaderFirst = false;
    List<WriterFirst.Reader> wfReaders = new ArrayList<>();
    List<WriterFirst.Writer> wfWriters = new ArrayList<>();
    List<ReaderFirst.Reader> rfReaders = new ArrayList<>();
    List<ReaderFirst.Writer> rfWriters = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        TestWRProblem testWRProblem = new TestWRProblem();
        testWRProblem.show();
    }

    TestWRProblem() throws IOException {
        boolean flag = true;
        while(flag) {
            System.out.println("选择操作：\n1.退出初始化 2.输入读者 3.输入写者 4.选择算法");
            Scanner scanner = new Scanner(System.in);
            int opt = scanner.nextInt();
            switch (opt) {
                case 1 -> {
                    flag = false;
                }
                case 2 -> {
                    System.out.println("输入两个值，分别为读者开始时间和读文件持续时间");
                    int latency = scanner.nextInt();
                    int duration = scanner.nextInt();
                    wfReaders.add(new WriterFirst.Reader(latency, duration));
                    rfReaders.add(new ReaderFirst.Reader(latency, duration));
                }
                case 3 -> {
                    System.out.println("输入两个值，分别为写者开始时间和写文件持续时间");
                    int latency = scanner.nextInt();
                    int duration = scanner.nextInt();
                    wfWriters.add(new WriterFirst.Writer(latency, duration));
                    rfWriters.add(new ReaderFirst.Writer(latency, duration));
                }
                case 4 -> {
                    System.out.println("1.读者优先 2.写者优先");
                    int chs = scanner.nextInt();
                    isReaderFirst = chs == 1;
                }
                default -> {
                }
            }
        }
    }

    void show() {
        if(isReaderFirst) {
            for(var val : rfWriters)
                val.start();
            for(var val : rfReaders)
                val.start();
        }else {
            for(var val : wfWriters)
                val.start();
            for(var val : wfReaders)
                val.start();
        }
    }
}
