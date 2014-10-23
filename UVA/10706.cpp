#include <stdio.h>
#include <math.h>

typedef long long ll;
const ll N = 2147483647;
const int w[] = {0, 10, 100, 1000, 10000, 100000};
const int M = 100000;
ll s[M];
ll num[M];

void init () {

	s[0] = num[0] = 0;
	s[1] = num[1] = 1;
	int cur = 1;
	for (int i = 2; s[i - 1] < N; i++) {

		if (i >= w[cur]) cur++;
		s[i] = 2 * s[i - 1] - s[i - 2] + cur;
		num[i] = s[i] - s[i - 1];
	}
}

int main () {

	init();
	int t;
	ll n;
	scanf ("%d", &t);
	char str[10];
	while (t--) {

		scanf ("%lld", &n);
		int i;

		for (i = 1; i < M ; i++)
			if (s[i] >= n)
				break;
		n -= s[i - 1];

		for (i = 1; i < M; i++)
			if (num[i] >= n)
				break;
		n -= num[i - 1];	

		sprintf (str, "%d", i);
		printf ("%c\n", str[n - 1]);
	}
	return 0;
}
