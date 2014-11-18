#include <cstdio>
#include <cstring>

const int maxn = 15;

int c[maxn];

void catalan () {

	c[1] = c[2] = 1;
	for (int i = 2; i <= 11; i++)
		c[i + 1] = c[i] * (4 * i - 6)/ i;
}

int main () {

	int n, cas = 0;
	catalan();
	while (scanf ("%d", &n) != EOF) {

		if (cas++)
			printf ("\n");
		printf ("%d\n", c[n + 2]);
	}
	return 0;
}
