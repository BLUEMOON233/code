import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.Semaphore;

public class ReaderFirst {
    static final int SECOND = 1000;
    static Semaphore muteReaderSemaphore = new Semaphore(1);
    static Semaphore muteWriterSemaphore = new Semaphore(1);
    static int readerCount = 0;

    public static void main(String[] args) throws InterruptedException {
        //readers:
        Reader reader_1 = new Reader(0, 2);
        Reader reader_2 = new Reader(1, 2);
        Reader reader_3 = new Reader(4, 2);
        //writers:
        Writer writer_1 = new Writer(2, 3);
        Writer writer_2 = new Writer(5, 2);
        //timer:
        final int processEnd = 10;
        Timer timer = new Timer();
        timer.scheduleAtFixedRate(new TimerTask() {
            int seconds = 0;
            @Override
            public void run() {
                if(seconds == processEnd) {
                    timer.cancel();
                }
                System.out.printf("当前为第%2d秒%n", seconds);
                seconds++;
            }
        }, 0, 1000);
        Thread.sleep(100);

        //process:
        reader_1.start(); //[0, 2] -> [0, 2]
        reader_2.start(); //[1, 3] -> [1, 3]
        writer_1.start(); //[2, 5] -> [3, 6]
        reader_3.start(); //[4, 6] -> [6, 8]
        writer_2.start(); //[5, 7] -> [9, 10]
    }

    static class Reader extends Thread {
        int latency;
        int duration;

        Reader(int latency, int duration) {
            this.latency = latency * SECOND;
            this.duration = duration * SECOND;
        }

        @Override
        public void run() {
            try {
                sleep(latency);
                System.out.printf("【读者进程%d】申请读文件。%n", this.getId());
                muteReaderSemaphore.acquire();
                if (readerCount == 0) muteWriterSemaphore.acquire();
                readerCount++;
                muteReaderSemaphore.release();

                System.out.printf("【读者进程%d】开始读文件。%n", this.getId());
                sleep(duration);
                System.out.printf("【读者进程%d】结束读文件。%n", this.getId());

                muteReaderSemaphore.acquire();
                readerCount--;
                if (readerCount == 0) muteWriterSemaphore.release();
                muteReaderSemaphore.release();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static class Writer extends Thread {
        int latency;
        int duration;

        Writer(int latency, int duration) {
            this.latency = latency * SECOND;
            this.duration = duration * SECOND;
        }

        @Override
        public void run() {
            try {
                sleep(latency);
                System.out.printf("【写者进程%d】申请写文件。%n", this.getId());
                muteWriterSemaphore.acquire();

                System.out.printf("【写者进程%d】开始写文件。%n", this.getId());
                sleep(duration);
                System.out.printf("【写者进程%d】结束写文件。%n", this.getId());

                muteWriterSemaphore.release();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}