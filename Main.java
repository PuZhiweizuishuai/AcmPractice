import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int n = sc.nextInt();
            Point[] points = new Point[n];
            TwoPoint[] twoPoints = new TwoPoint[n];
            UF uf = new UF(n);
            for (int j = 0; j < n; j++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                int z = sc.nextInt();
                Point point = new Point(x, y, z, j);
                points[j] = point;
            }

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j != k) {
                        points[j].addPoint(points[k]);
                    }
                }
                twoPoints[j] = new TwoPoint(points[j], points[j].point);
            }
            System.out.printf("%.2f\n", Kruskal(twoPoints, uf));
        }
        sc.close();
    }

    public static double Kruskal(TwoPoint[] twoPoints, UF uf) {
        Arrays.sort(twoPoints);
        int total = 0;
        double sum = 0;
        for (int i = 0; i < twoPoints.length; i++) {
            int p = uf.find(twoPoints[i].pointOne.index);
            int q = uf.find(twoPoints[i].pointTwo.index);
            if (uf.connected(p, q)) {
                continue;
            } else {
                uf.unions(p, q);
                total++;
                sum += twoPoints[i].distance;
                if (total == twoPoints.length - 1)
                    break;
            }
        }
        return sum;
    }
}

class UF {
    private int[] ID;

    public UF(int n) {
        ID = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            ID[i] = -1;
        }
    }

    public int find(int p) {
        if (ID[p] == -1)
            return p;
        return ID[p] = find(ID[p]);
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

class Point {
    public int x;
    public int y;
    public int z;
    public int index;
    public Point point;
    double twoPoint = 9999999999.0;

    public Point(int x, int y, int z, int index) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.index = index;
    }

    public double twoPointDistance(Point P) {
        double X = (this.x - P.x) * (this.x - P.x);
        double Y = (this.y - P.y) * (this.y - P.y);
        double Z = (this.z - P.z) * (this.z - P.z);
        return Math.sqrt(X + Y + Z);
    }

    public void addPoint(Point point) {
        if (twoPoint > twoPointDistance(point)) {
            twoPoint = twoPointDistance(point);
            this.point = point;
        }
    }
}

class TwoPoint implements Comparable<TwoPoint> {
    public Point pointOne;
    public Point pointTwo;
    public double distance;

    public TwoPoint(Point pointOne, Point pointTwo) {
        this.pointOne = pointOne;
        this.pointTwo = pointTwo;
        distance = pointOne.twoPointDistance(pointTwo);
    }

    public int compareTo(TwoPoint twoPoint) {
        if (this.distance > twoPoint.distance) {
            return 1;
        } else if (this.distance < twoPoint.distance) {
            return -1;
        } else {
            return 0;
        }
    }
}
