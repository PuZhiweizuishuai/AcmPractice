import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class KruskalMST {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Edge[] edges = new Edge[m];
        UF uf = new UF(n);
        for (int i = 0; i < m; i++) {
            Edge edge = new Edge();
            edge.u = sc.nextInt();
            edge.v = sc.nextInt();
            edge.w = sc.nextInt();
            edges[i] = edge;
        }

        System.out.println(Kruskal(edges, uf));
        sc.close();
    }

    public static int Kruskal(Edge[] edges, UF uf) {
        Arrays.sort(edges);
        int sum = 0;
        for (int i = 0; i < edges.length; i++) {
            int p = uf.find(edges[i].u);
            int q = uf.find(edges[i].v);
            if (uf.connected(p, q)) {
                continue;
            } else {
                uf.unions(p, q);
                sum += edges[i].w;
            }
        }
        return sum;
    }
}

class UF {
    private int[] ID;

    public UF(int n) {
        ID = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            ID[i] = -1;
        }
    }

    public int find(int p) {
        while (ID[p] != -1) {
            p = ID[p];
        }
        return p;
    }

    public void unions(int p, int q) {
        if (p == q) {
            return;
        }
        ID[p] = q;
    }

    public boolean connected(int pRoot, int qRoot) {
        if (pRoot == qRoot)
            return true;
        else
            return false;
    }
}

class Edge implements Comparable<Edge> {
    public int u;
    public int v;
    public int w;

    @Override
    public int compareTo(Edge that) {
        if (this.w < that.w) {
            return -1;
        } else if (this.w > that.w) {
            return 1;
        } else {
            return 0;
        }
    }
}