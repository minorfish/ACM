import java.util.*;
import java.math.*;
import java.io.*;

public class Main {

	static BigInteger f[] = new BigInteger[1005];

	public static void init() {

		f[0] = BigInteger.valueOf(1); 
		f[1] = BigInteger.valueOf(2);
		for (int i = 2; i <= 1000; i++)
			f[i] = f[i - 1].add(f[i - 2]);
	}

	public static void main(String args[]) {

		Scanner cin = new Scanner(System.in);
		int n;
		init();

		while (cin.hasNext()) {

			n = cin.nextInt();
			System.out.println(f[n]);
		}
	}
}

