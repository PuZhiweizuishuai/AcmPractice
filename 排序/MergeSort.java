/**
 * 归并排序
 * @author PuZhiwei
 * */
public class MergeSort {
    /**
     * 归并所需辅助数组
     * */
    private static Comparable[] aux;

    public static void sort(Comparable[] a) {
        aux = new Comparable[a.length];
        sort(a, 0, a.length-1);
    }


    /**
     * 递归调用排序
     * */
    private static void sort(Comparable[] a, int lo, int hi) {
        if(hi <= lo) {
            return;
        }
        int mid = lo + (hi - lo) / 2;
        // 将左半边排序
        sort(a, lo, mid);
        // 将右半边排序
        sort(a, mid + 1, hi);
        merge(a, lo, mid, hi);
    }

    /**
     * 原地归并的抽象方法
     * */
    public static void merge(Comparable[] a, int lo, int mid, int hi) {
        int i = lo, j = mid + 1;
        // 将 a[lo..hi] 复制到 aux[lo..hi]
        for(int k = lo; k <= hi; k++) {
            aux[k] = a[k];
        }

        // 归并到 a[lo..hi]
        for(int k = lo; k <= hi; k++) {
            if(i > mid) {
                a[k] = aux[j++];
            } else if(j > hi) {
                a[k] = aux[i++];
            } else if(less(aux[j], aux[i])) {
                a[k] = aux[j++];
            } else {
                a[k] = aux[i++];
            }
        }
    }

    /**
     * 如果 a 大于 b 返回 true
     * */
    private static boolean less(Comparable a, Comparable b) {
        return a.compareTo(b) < 0;
    }
}
