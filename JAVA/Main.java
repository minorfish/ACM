import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

	public static BigInteger GCD (BigInteger num1, BigInteger num2) {

		if (num2.equals(BigInteger.ZERO))
			return num1;
		return GCD(num2, num1.mod(num2));
	}

	public static void main(String args[]) {

		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));

		int T;
		T = cin.nextInt();
		BigInteger L, W;

		for (int i = 1; i <= T; i++) {

			L = cin.nextBigInteger(2);
			W = cin.nextBigInteger(2);
					
			BigInteger ans = GCD(L, W);

			cout.printf("Case #%d: ", i);
			cout.println(ans.toString(2));
		}
		cin.close();
		cout.close();
	}
}
