#include <stdio.h>

int t;
int main () {
	
	scanf ("%d", &t);
	double sum, x, y;
	int z;
	while (t--) {
	
		sum = 0;
		for (int i = 0; i < 12; i++)  {

			scanf ("%lf", &x);
			sum += x;
		}
		sum /= 12;
		y = sum * 100 + 0.5;
		z = y;
		int d = 0;
		while (z % 10 == 0 && d < 2) {
			
			z /= 10;
			d++;
		}
		printf ("$");
		if (!d)
			printf("%.2lf\n", sum);
		else if (d == 1)
			printf ("%.1lf\n",sum);
		else 
			printf ("%d\n", (int) sum);			
	}
	return 0;
}
