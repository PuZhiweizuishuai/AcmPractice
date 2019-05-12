import java.util.*;

public class PrimePath {

    public static boolean[] isPrime = new boolean[10000];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        setIsPrime();
        int n = scanner.nextInt();
        while (n-- != 0) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            int length = 0;
            Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
            Set<Integer> set = new HashSet<>();
            queue.add(new Pair<>(start, 0));
            while (!queue.isEmpty()) {
                Pair<Integer, Integer> s = queue.poll();
                if (s.first == end) {
                    length = s.second;
                    break;
                }
                for (int prime : collection(s.first)) {
                    if (isPrime[prime] && !set.contains(prime)) {
                        set.add(prime);
                        queue.add(new Pair<>(prime, s.second + 1));
                    }
                }
            }
            System.out.println(length);
        }
    }

    public static void setIsPrime() {
        int i, j;
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (i = 2; i < isPrime.length; i++) {
            if (isPrime[i]) {
                for (j = i + i; j < isPrime.length; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    public static Collection<Integer> collection(int prime) {
        List<Integer> list = new ArrayList<>();
        int digit1 = prime / 1000;
        int digit234 = prime - digit1 * 1000;
        int digit2 = prime % 1000 / 100;
        int digit134 = prime - digit2 * 100;
        int digit3 = prime % 100 / 10;
        int digit124 = prime - digit3 * 10;
        int digit4 = prime % 10;
        int digit123 = prime - digit4;
        for (int i = 0; i < 10; i++) {
            if (i != 0) {
                list.add(digit234 + 1000 * i);
            }
            list.add(digit134 + 100 * i);
            list.add(digit124 + 10 * i);
            list.add(digit123 + i);
        }
        return list;
    }

    public static class Pair<T1, T2> {
        private T1 first;
        private T2 second;

        public Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }

        public T1 getFirst() {
            return first;
        }

        public T2 getSecond() {
            return second;
        }
    }
}