#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>

const int maxn = 1000;
const int N = 10;
const int M = 100;
const double esp = 1e-3;

int main () {

	srand(time(0));
	int T = rand() % (maxn - 1) + 1;
	printf ("%d\n", T);

	while (T--) {

		double l = rand() /(double)(RAND_MAX/M);
		double r = rand() /(double)(RAND_MAX/M);
		printf ("%.4lf %.4lf\n", l, r);	

		int n = rand() % (N - 1) + 1;
		printf ("%d\n", n);
		for (int i = 0; i < n; i++) {

			int seed = rand() % N;
			if (seed == 0)
				printf ("0");
			else {
				double fnum = rand() / (double)(RAND_MAX/M);
				printf ("%.4lf", fnum);
			}

			if (i != n - 1) 
				printf (" ");
			else 
				printf ("\n");
		}
			
	}
	return 0;
}
