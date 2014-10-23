#include <cstdio>
#include <cstring>

int main () {

	int T;
	int n, m;
	int score;

	scanf ("%d", &T);
	while (T--) {

		int sum1 = 0;
		int sum2 = 0;
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n - 1; i++) {

			scanf ("%d", &score);
			sum1 += score;
		}

		for (int i = 0; i < m; i++) {

			scanf ("%d", &score);
			sum2 += score;
		}

		if (sum1 % (n - 1) == 0)
			sum1 = sum1 / (n - 1) - 1;
		else
			sum1 = sum1 / (n - 1);
		sum2 = sum2 / m + 1;

		printf ("%d %d\n", sum2, sum1);
	}
	return 0;
}
