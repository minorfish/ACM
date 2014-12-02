import java.util.*;
import java.math.*;
import java.io.*;

public class Main {

	public static void main(String args[]) {

		Scanner cin = new Scanner(System.in);
		BigInteger n;
		while (cin.hasNext()) {

			n = cin.nextBigInteger();
			if (n.equals(BigInteger.ZERO))
				System.out.println(1);
			else 
				System.out.println(BigInteger.valueOf(2).add(n.multiply(n.subtract(BigInteger.valueOf(1)))));
		}
	}
}

