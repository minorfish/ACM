#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double p, q, r, s, t, u;
const double eps = 1e-8;

double f(double m) {

	return p * exp(-m) + q * sin(m) + r * cos(m) + s * tan(m) + t * m * m + u;
}

double cal () {

	double l = 0;
	double r = 1;
	double m;
	double sum;
	while (r - l > eps) {
		
		m = l + (r - l) / 2;
		if (f(m) < 0)
			r = m;
		else
			l = m;
	}
	return m;
}

int main () {

	while (scanf ("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) != EOF) {
			
		if (f(0) < 0 || f(1) > 0)
			printf ("No solution\n");
		else
			printf ("%.4lf\n", cal());
	}
	return 0;
}
