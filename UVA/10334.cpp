#include <cstdio>
#include <cstring>

const int maxn = 1e3 + 5;
typedef long long ll;
ll f[maxn];

void init () {

	f[0] = 1;
	f[1] = 2;
	for (int i = 2; i <= maxn - 5; i++)
		f[i] = f[i - 1] + f[i - 2];
}

int main () {

	int n;
	init();
	while (scanf ("%d", &n) == 1) {

		printf ("%lld\n", f[n]);
	}
	return 0;
}
