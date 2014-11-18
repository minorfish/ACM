import java.util.*;
import java.math.*;
import java.io.*;

public class Main {

	static BigInteger f[] = new BigInteger[2005];

	public static void init() {

		f[1] = BigInteger.valueOf(1); 
		f[2] = BigInteger.valueOf(3);
		for (int i = 3; i <= 2000; i++)
			f[i] = BigInteger.valueOf(3).multiply(f[i - 1]).subtract(f[i - 2]);
	}

	public static void main(String args[]) {

		Scanner cin = new Scanner(System.in);
		int n;
		init();

		while (true) {

			n = cin.nextInt();
			if (n == 0)
				break;

			System.out.println(f[n]);
		}
	}
}

