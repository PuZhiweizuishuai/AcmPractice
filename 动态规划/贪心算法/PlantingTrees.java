import java.util.Arrays;
import java.util.Scanner;
/**
 * 问题：
 * 某条街被划为 n 条路段，每个路段最多可以种一棵树。现在居民
 * 们给出了 h 组建议，每组建议包含三个整数 b,e,t 表示居民希望
 * 在路段 b 到 e 之间至少要种 t 棵树。这些建议所给路段的区间可
 * 以交叉。
 * 请问：如果要满足所有居民的建议，至少要种多少棵树。
 * 
 * 
 * 思路：
 * 所以我们按照区间末尾标号将输入的数据进行由小到大排序，
 * 那么按照排好顺序进行“倒序植树”，直到达到该区间所需要的
 * 树的数量，再进行下一个区间的遍历。
 */
public class PlantingTrees {
    public static void main(String[] args) {
        // 数的数量
        int sum = 0;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int h = sc.nextInt();
        Tree[] tree = new Tree[h];
        // 检测编号为i的单元是否已经种上了树
        boolean[] flag = new boolean[n+10];
        for(int i = 0; i < h; i++) {
            Tree t = new Tree();
            t.b = sc.nextInt();
            t.e = sc.nextInt();
            t.t = sc.nextInt();
            tree[i] = t;
        }
        
        Arrays.sort(tree);
        
        for(int i = 0; i < h; i++) {
            // 表示当前已经种了多少棵树，判断 nowTreeNumber 与需要种的数量是否相等
            int nowTreeNumber = 0;
            for(int j = tree[i].b; j <= tree[i].e; j++) {
                if(flag[j])
                    nowTreeNumber++;
                if(nowTreeNumber == tree[i].t)
                    break;
            }

            if(nowTreeNumber < tree[i].t) {
                for(int j = tree[i].e; j >= tree[i].b; j--) {
                    if(!flag[j]) {
                        flag[j] = true;
                        nowTreeNumber++;
                        sum++;
                        if(nowTreeNumber == tree[i].t) {
                            break;
                        }
                    }
                }
            }
        }
        System.out.println(sum);
    }
}

class Tree implements Comparable<Tree> {
    /**
     * 表示居民希望在路段 bbb 到 eee 之间至少要种 ttt 棵树
     */
    public int b;
    public int e;
    public int t;

    @Override
    public int compareTo(Tree O) {
        if(this.e > O.e) {
            return 1;
        } else if(this.e < O.e) {
            return -1;
        } else {
            return 0;
        }
    }
}