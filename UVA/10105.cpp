#include <cstdio>
#include <cstring>

typedef long long ll;

const int maxn = 13;
ll c[maxn];

void init () {

	c[0] = 1;
	for (int i = 1; i < maxn; i++)
		c[i] = c[i - 1] * i;
}

int main () {

	int N, K, num;
	init();

	while (scanf ("%d%d", &N, &K) != EOF) {

		ll ans = c[N];
		for (int i = 0; i < K; i++) {
			scanf ("%d", &num);
			ans /= c[num];
			N -= num;
		}

		printf ("%lld\n", ans);
	}
	return 0;
}
