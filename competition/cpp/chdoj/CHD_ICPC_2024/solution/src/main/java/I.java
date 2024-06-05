import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class I {
    private static long mergeSort(int[] arr, int[] copy, int l, int r) {
        long ret = 0;
        if (l == r) {
            return ret;
        }
        int mid = (l + r) >> 1;
        ret += mergeSort(arr, copy, l, mid);
        ret += mergeSort(arr, copy, mid + 1, r);
        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j])
                copy[k++] = arr[i++];
            else {
                copy[k++] = arr[j++];
                ret += (mid - i + 1);
            }
        }
        while (i <= mid) copy[k++] = arr[i++];
        while (j <= r) copy[k++] = arr[j++];
        for (int p = l; p <= r; p++)
            arr[p] = copy[p];
        return ret;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i <= n - 1; i++)
            a[i] = scanner.nextInt();
        for (int i = 0; i <= n - 1; i++)
            b[i] = scanner.nextInt();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i <= n - 1; i++)
            map.put(b[i], i + 1);
        for (int i = 0; i <= n - 1; i++)
            a[i] = map.get(a[i]);
        System.out.println(mergeSort(a, b, 0, n - 1));
    }
}
