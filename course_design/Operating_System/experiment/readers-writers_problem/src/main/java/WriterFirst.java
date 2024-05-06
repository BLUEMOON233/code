import java.util.concurrent.Semaphore;

public class WriterFirst {
    static final int SECOND = 1000;
    static Semaphore muteReaderSemaphore = new Semaphore(1);
    static Semaphore muteWriterSemaphore = new Semaphore(1);
    static Semaphore semX = new Semaphore(1);
    static Semaphore semY = new Semaphore(1);
    static Semaphore semZ = new Semaphore(1);
    static int readerCount = 0;
    static int writerCount = 0;

    public static void main(String[] args) {
        //readers:
        WriterFirst.Reader reader_1 = new WriterFirst.Reader(3, 5);
        WriterFirst.Reader reader_2 = new WriterFirst.Reader(5, 2);
        WriterFirst.Reader reader_3 = new WriterFirst.Reader(6, 5);
        //writers:
        WriterFirst.Writer writer_1 = new WriterFirst.Writer(4, 5);
        WriterFirst.Writer writer_2 = new WriterFirst.Writer(5, 3);
        //process:
        reader_1.start();
        writer_1.start();
        reader_2.start();
        reader_3.start();
        writer_2.start();
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
                semZ.acquire();
                muteReaderSemaphore.acquire();
                semX.acquire();
                if(readerCount == 0) muteWriterSemaphore.acquire();
                readerCount++;
                semX.release();
                muteReaderSemaphore.release();
                semZ.release();

                System.out.printf("【读者进程%d】开始读文件。%n", this.getId());
                sleep(duration);
                System.out.printf("【读者进程%d】结束读文件。%n", this.getId());

                semX.acquire();
                readerCount--;
                if(readerCount == 0) muteWriterSemaphore.release();
                semX.release();
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
                semY.acquire();
                if(writerCount == 0) muteReaderSemaphore.acquire();
                writerCount++;
                semY.release();

                muteWriterSemaphore.acquire();

                System.out.printf("【写者进程%d】开始写文件。%n", this.getId());
                sleep(duration);
                System.out.printf("【写者进程%d】结束写文件。%n", this.getId());

                muteWriterSemaphore.release();

                semY.acquire();
                writerCount--;
                if(writerCount == 0) muteReaderSemaphore.release();
                semY.release();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
