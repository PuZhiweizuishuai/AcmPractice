import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int numberOfCatalan = 101; 
		BigInteger[] digis = generateCatalan(numberOfCatalan);
		Scanner scanner = new Scanner(System.in);
		int number;
		while (true) {
			number = scanner.nextInt();
			if (number == -1)
				break;
			String answer = digis[number].toString();
			System.out.println(answer);
		}
		scanner.close();
	}

	public static BigInteger[] generateCatalan(int numberOfCatalan) {
		BigInteger digis[] = new BigInteger[numberOfCatalan + 1];
		BigInteger x = BigInteger.ONE; 
		digis[1] = x;
		int y = 0;
		int z = 0;
		for (int counter = 2; counter <= numberOfCatalan; counter++) {
			y = 4 * counter - 2;
			z = counter + 1;
			digis[counter] = digis[counter - 1].multiply(new BigInteger(""
					+ y));
			digis[counter] = digis[counter].divide(new BigInteger("" + z));
		}
		return digis;
	}
}
