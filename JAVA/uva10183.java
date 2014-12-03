import java.util.*;
import java.math.*;
import java.io.*;
import java.lang.String.*;

public class Main {

	static BigInteger f[] = new BigInteger[10005];
	static int n = 2;
	public static void init () {

		f[1] = BigInteger.valueOf(1);
		f[2] = BigInteger.valueOf(2);
		BigInteger c = BigInteger.valueOf(10).pow(100);

		for (int i = 3; f[i - 1].compareTo(c) != 1; i++) {
			f[i] = f[i - 1].add(f[i - 2]);
			n++;
		}
	}

	public static int upper_bound(BigInteger a) {
		
		int l = 1;
		int r = n;
		int m, num;

		while (l < r) {
			
			m = (l + r) / 2;
			num = a.compareTo(f[m]);
			if (num <= 0)
				r = m;
			else
				l = m + 1;
		}
		return r; 		
	}
	
	public static void main(String args[]) {

		Scanner cin = new Scanner(System.in);
		init();
		
		BigInteger a, b;
		while (cin.hasNext()) {

			a = cin.nextBigInteger();
			b = cin.nextBigInteger();
			if (a.equals(BigInteger.ZERO) && b.equals(BigInteger.ZERO))
				break;
			int x = upper_bound(b);
			int y = upper_bound(a) - 1;


		//	System.out.println(f[x]);
		//	System.out.println(f[y]);
			/*for (int i = 1; i <= 10; i++)
				System.out.println(f[i]);*/
			if (f[x].compareTo(b) != 0)
				x--;
			System.out.println(x - y);				
		}
	}
}

