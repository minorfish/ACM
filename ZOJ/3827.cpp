#include <cstdio>
#include <cstring>
#include <cmath>

const double esp = 1e-9;

int main () {

	int T, n;
	double b, p;
	char str[10];

	scanf ("%d", &T);
	while (T--) {

		scanf ("%d%s", &n, str);		
		if (str[0] == 'b')
			b = 2;
		else if (str[0] == 'n')
			b = exp(1.0);
		else
			b = 10;

		double ans = 0;
		for (int i = 0; i < n; i++) {

			scanf ("%lf", &p);
			if (fabs(p) > esp) { 
				p /= 100.0;
				ans += p * log(p) / log(b);	
			}
		}

		printf ("%.12lf\n", -ans);
	}
}
