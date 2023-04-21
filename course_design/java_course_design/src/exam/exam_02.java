package exam;

public class exam_02 {
    public static void main(String args[]) {
        int[][] A = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };
        int[][] B = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };
        int[][] answer = mult(A, B);
        System.out.println("最终输出结果为：");
        for (int[] row : answer) {
            for (int col : row) System.out.print(col + "\t");
            System.out.println();
        }
    }

    static int[][] mult(int[][] A, int[][] B) {
        int n = A.length, m = A[0].length, check_m = B.length, s = B[0].length;
        if (m != check_m) {
            System.out.println("输入矩阵无法实现乘法，返回空值");
            int[][] rs = {{0}};
            return rs;
        }
        int[][] rs = new int[n][s];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < s; k++)
                    rs[i][k] += A[i][j] * B[j][k];
        return rs;
    }

}
