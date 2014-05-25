#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

const double esp = -1e-9;

int main () {

	long long t, n, m, v, k;
	long long count;
	cin>>t;
	while (t--) {

		count = 0;
		cin >>n >>m >>v >>k;

		if (n <= m) 
			count = 0;
		else {

			long long add = (m - v) * k - m;
			if ( m <= v || k <= 0 || add <= 0)
				count = -1;
			else {

				double a0 = (double) (n - m) / (double) (add);
				double temp = a0 * (k - 1) + 1;
				for (long long i = 1; ; i++)
					if ( pow ((double)k, (double)i) - temp > esp) {

						count = i;
						break;
					}
			}
		}
		cout <<count <<endl;

	}
	return 0;
}
