import java.util.*;
import java.math.*;
import java.io.*;

public class Main {

	public static BigInteger sqrt(BigInteger ans) {
		
		BigInteger num = BigInteger.ZERO;	
		BigInteger res = BigInteger.ZERO;
		BigInteger div;
		String str = "0" + ans.toString();
	
		int len = str.length();
		int i = len % 2;

		for (; i < len; i += 2) {
			
			num = num.multiply(BigInteger.valueOf(100)).add(new BigInteger(str.substring(i, i + 2)));
			div = res.multiply(BigInteger.valueOf(20));
			for (int j = 0; j < 10; j++) {
				if (div.add(BigInteger.valueOf(j + 1)).multiply(BigInteger.valueOf(j + 1)).compareTo(num) > 0) {

					num = num.subtract(div.add(BigInteger.valueOf(j)).multiply(BigInteger.valueOf(j)));
					res = res.multiply(BigInteger.valueOf(10)).add(BigInteger.valueOf(j));			
					break;
				}
			}
		}
		return res;
	}

	public static void main(String args[]) {

		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		while (T > 0) {

			BigInteger n = cin.nextBigInteger();
			System.out.println(sqrt(n));
			T--;
			if (T > 0)
				System.out.println();
		}
	}
}

