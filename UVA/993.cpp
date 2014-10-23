#include <stdio.h>
#include <string.h>

const int N = 10;
int c[N];
int n;

bool factor() {

	memset (c, 0, sizeof (c));
	for (int i = N - 1; i >= 2; i--) {

		if (n == 1)
			return true;
		while (n % i == 0) {

			c[i]++;
			n /= i;
		}
	}
	if (n == 1)
		return true;
	return false;
}

int main () {

	int t;
	int c6;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d", &n);
		if (n != 1) {

			if (!factor())
				printf ("-1\n");
			else {
				for (int i = 2; i < 10 ; i++) 
					for (int j = 0; j < c[i]; j++)
						printf ("%d", i);
				printf ("\n");
			}
		} else 
			printf ("1\n");
	}
	return 0;
}
