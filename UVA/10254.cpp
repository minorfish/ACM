#include <cstdio>
#include <cstring>

typedef long long ll;
const int maxn = 1e4 + 5;
ll f[maxn];

void init () {

	f[1] = 1;
	f[2] = 3;
	for (int i = 3; i <= maxn - 5; i++) 
		f[i] = 2 * f[i - 2] + f[2];
}

int main () {

	init();
	int n;
	while (scanf ("%d", &n) == 1) {

		printf ("%lld\n", f[n]);
	}
	return 0;
}
