import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.function.Function;

public class BankersAlgorithm {
    int N; //进程数
    int M; //资源种类数
    int[] available;
    int[][] max;
    int[][] allocation;
    int[][] need;

    int requestID;
    int[] request;

    BankersAlgorithm() {
        init();
        run();
    }

    void init() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("======================");
        System.out.print("请输入进程数：");
        N = scanner.nextInt();
        System.out.print("请输入资源种类数：");
        M = scanner.nextInt();
        available = new int[M];
        max = new int[N][M];
        allocation = new int[N][M];
        need = new int[N][M];
        request = new int[M];

        System.out.println("请输入资源可用向量：");
        for (int i = 0; i <= M - 1; i++)
            available[i] = scanner.nextInt();
        System.out.println("请输入最大需求矩阵：");
        for (int i = 0; i <= N - 1; i++)
            for (int j = 0; j <= M - 1; j++)
                max[i][j] = scanner.nextInt();
        System.out.println("请输入分配矩阵：");
        for (int i = 0; i <= N - 1; i++)
            for (int j = 0; j <= M - 1; j++)
                allocation[i][j] = scanner.nextInt();

        for (int i = 0; i <= N - 1; i++)
            for (int j = 0; j <= M - 1; j++)
                need[i][j] = max[i][j] - allocation[i][j];

        System.out.println("输入发出请求向量的进程编号：");
        requestID = scanner.nextInt();

        System.out.println("输入请求向量：");
        for (int i = 0; i <= M - 1; i++)
            request[i] = scanner.nextInt();
        System.out.println("======================");
    }

    boolean checkIsLegal() {
        for (int i = 0; i <= M - 1; i++) {
            if (request[i] > need[requestID][i]) {
                System.out.println("发出请求的进程申请资源量大于该进程宣布的最大值，算法出错");
                return false;
            }
            if (request[i] > available[i]) {
                System.out.println("当前无足够资源，需等待");
                return false;
            }
        }
        return true;
    }

    boolean compare(int currentID, int[] work) {
        for (int i = 0; i <= M - 1; i++) {
            if (need[currentID][i] > work[i]) {
                return false;
            }
        }
        return true;
    }

    void security() {
        List<Integer> safeSequence = new ArrayList<>();
        int[] work = available.clone();
        boolean[] finish = new boolean[N];
        Arrays.fill(finish, false);


        while (true) {
            int currentID = -1;
            for (int i = 0; i <= N - 1; i++) {
                if (finish[i]) continue;
                if (compare(i, work)) {
                    currentID = i;
                    break;
                }
            }
            if (currentID == -1) break;
            for (int i = 0; i <= M - 1; i++) {
                work[i] += allocation[currentID][i];
            }
            finish[currentID] = true;
            safeSequence.add(currentID);
        }

        for (int i = 0; i <= N - 1; i++) {
            if (!finish[i]) {
                System.out.println("不存在安全序列");
                return;
            }
        }

        work = available.clone();
        System.out.print("存在安全序列：\n{");
        for (int i = 0; i <= safeSequence.size() - 2; i++) {
            System.out.format("P%d, ", safeSequence.get(i));
        }
        System.out.format("P%d}\n", safeSequence.get(safeSequence.size() - 1));
        System.out.println("对资源分配情况进行分析：");
        System.out.format("\t\t  Max\t\t Need\t\tAllocation\t\t Work\t\tWork+Allocation\n");
        for (int val : safeSequence) {
            System.out.format("P%d\t\t", val);
            for (int i = 0; i <= M - 1; i++)
                System.out.printf("%2d ", max[val][i]);
            System.out.print("\t");
            for (int i = 0; i <= M - 1; i++)
                System.out.printf("%2d ", need[val][i]);
            System.out.print("\t");
            for (int i = 0; i <= M - 1; i++)
                System.out.printf("%2d ", allocation[val][i]);
            System.out.print("\t");
            for (int i = 0; i <= M - 1; i++)
                System.out.printf("%2d ", work[i]);
            System.out.print("\t\t");
            for (int i = 0; i <= M - 1; i++) {
                work[i] += allocation[val][i];
                System.out.printf("%2d ", work[i]);
            }
            System.out.print("\n");
        }
    }

    void run() {
        if (!checkIsLegal()) {
            return;
        }
        for (int i = 0; i <= M - 1; i++) {
            available[i] -= request[i];
            allocation[requestID][i] += request[i];
            need[requestID][i] -= request[i];
        }
        security();
    }

    public static void main(String[] args) {
        BankersAlgorithm bankersAlgorithm = new BankersAlgorithm();
    }
}

/*
5
3
3 3 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

1
1 0 2
 */
