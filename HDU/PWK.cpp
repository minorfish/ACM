#include <stdio.h>

const double esp = 1e-9;

int main () {
	
	double x, y;
	while (scanf ("%lf%lf", &x, &y) == 2) {

		if (x > y) 
			printf ("-1\n");

		else {
		
			double s, sum, max;
			int count;
			s = (y + 1 - esp) / x;
			sum = 1;
			count = (int)x - 1;
			int k;
			for (int i = 1; i <= (int) x; i++) {

				max = s * i;
				k = (int) (max - sum);
				sum += k;
				count += k;
				//printf ("%lf\n", sum);
				sum = sum * (i + 1) / i;
			}
			printf ("%d\n", count);
		}
	}
	return 0;
}
