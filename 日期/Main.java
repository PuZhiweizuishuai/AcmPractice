import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Calendar calendar = Calendar.getInstance();
		int year = sc.nextInt();
		int month = sc.nextInt();
		int day = sc.nextInt();

		calendar.set(year, month - 1, day);

		calendar.add(Calendar.DAY_OF_YEAR, 10000);

		System.out.printf("%d-%d-%d\n", calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH) + 1,
				calendar.get(Calendar.DAY_OF_MONTH));
		sc.close();
	}
}