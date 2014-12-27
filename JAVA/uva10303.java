import java.util.*;
import java.math.*;
import java.io.*;

public class Main {

	static BigInteger f[] = new BigInteger[1005];
	public static void init () {

		f[1] = BigInteger.valueOf(1);
		f[2] = BigInteger.valueOf(1);

		BigInteger c;
		for (int i = 2; i <= 1001; i++) {
			c = BigInteger.valueOf(i);
			f[i + 1] = f[i].multiply(BigInteger.valueOf(4).multiply(c).subtract(BigInteger.valueOf(6))).divide(c);
		}
	}

	public static void main(String args[]) {

		Scanner cin = new Scanner(System.in);
		init();
		
		while (cin.hasNext()) {

			int n = cin.nextInt();
			System.out.println(f[n + 2]);				
		}
	}
}

