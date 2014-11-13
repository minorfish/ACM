#include <cstdio>
#include <cstring>

int main () {

	double n, m, k;
	while (scanf ("%lf%lf%lf", &n, &m, &k) != EOF) {

		double tmp1 = m + n;
		double tmp2 = (m + n - k - 1.0);
		double ans = n /tmp1 * (m / tmp2) + m /tmp1 * ((m - 1)/tmp2);
		printf ("%.5lf\n", ans); 
	}
	return 0;
}
