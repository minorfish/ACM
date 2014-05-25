#include <stdio.h>
#include <math.h>

int t;

int main () {

	scanf ("%d", &t);
	int g, l, k, count, ans;
	while (t--) {

		scanf ("%d%d", &g, &l);
		ans = 1;
		if (l % g != 0)
			printf ("0\n");
		else {

			l /= g;
			k = sqrt(l);	
			for (int i = 2; i <= k; i++) {
				
				count = 0;
				if (l % i == 0) {

					while (l % i == 0) {

						l /= i;
						count++;
					}
				}
				if (count)
					ans *= 6 * count;
			}
			if (l != 1)
				ans *= 6;
			printf ("%d\n", ans);
		}
	}
}
