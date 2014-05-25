#include <stdio.h>
#include <string.h>

const int N = 11;
const char str[N][3] = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "D-", "F"};
const double num[N] = {4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 1.3, 1.0, 0};

int main () {

	int n, d, d_n;
	char s[N];
	double sum;
	while (scanf ("%d", &n) == 1) {

		sum = 0;
		d_n = 0;
		for (int i = 0; i < n; i++) {

			scanf ("%d%s", &d, s);
			for (int i = 0; i < N; i++)
				if (strcmp (s, str[i]) == 0) {

					sum += num[i] * d;
					d_n += d;
					break;
				}
		}
		if (d_n)
			printf ("%.2lf\n", sum / d_n);
		else
			printf ("0.00\n");
	}
	return 0;
}
