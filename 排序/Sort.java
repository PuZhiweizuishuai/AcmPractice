/**
 * 初级排序算法
 * 选择, 插入, 希尔排序
 * @author PuZhiwei
 * @version 1.0
 * */

public class Sort {
    /**
     * 如果 a 大于 b 返回 true
     * */
    private static boolean less(Comparable a, Comparable b) {
        return a.compareTo(b) < 0;
    }

    /**
     * 交换 a[i] 与 a[j]
     * */
    private static void exch(Comparable[] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    /**
     * 判断数组是否升序排列
     * */
    public static boolean isSorttd(Comparable[] a) {
        int N = a.length;
        for(int i = 1; i < N; i++) {
            if(less(a[i], a[i-1])) {
                return false;
            }
        }
        return true;
    }


    /**
     * 选择排序
     * 升序排序
     * */
    public static void selectSort(Comparable[] a) {
        int N = a.length;
        for(int i = 0; i < N; i++) {
            int min = i;
            // 查找最小值
            for(int j = i + 1; j < N; j++) {
                // 保留最小值位置
                if(less(a[j], a[min])) {
                    min = j;
                }
            }
            if(min != i) {
                exch(a, i, min);
            }
        }
    }

    /**
     * 插入排序
     * 升序排序
     * */
    public static void insertSort(Comparable[] a) {
        int N = a.length, i, j;
        // 将 a[i] 插入到 a[i-1], a[i-2], a[i-3]...之中
        for(i = 0; i < N; i++) {
            Comparable temp = a[i];
            for(j = i; j > 0 && less(temp, a[j-1]); j--) {
                a[j] = a[j - 1];
            }
            a[j] = temp;
        }
    }

    /**
     * 希尔排序
     * 升序排序
     * */
    public static void shellSort(Comparable[] a) {
        int N = a.length;
        int h = 1;
        while (h < N/3) {
            h = 3 * h + 1;
        }
        while (h >= 1) {
            for(int i = h; i < N; i++) {
                for(int j = i; j >= h && less(a[j], a[j - h]); j -= h) {
                    exch(a, j, j - h);
                }
            }
            h = h / 3;
        }
    }

}
