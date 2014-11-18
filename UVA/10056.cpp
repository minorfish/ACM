#include <cstdio>
#include <cstring>
#include <cmath>

const double esp = 1e-9;

int main () {

	int T;
	scanf ("%d", &T);
	
	int n, I;
	double p;
	while (T--) {

		scanf ("%d%lf%d", &n, &p, &I);
		if (p < esp) {
			printf ("0.0000\n");
			continue;
		}
		double q = 1.0 - p;
		double ans = p * pow(q, I - 1)/(1.0 - pow(q, n));	
		printf ("%.4lf\n", ans);
	}
	return 0;
}
