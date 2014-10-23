#include <cstdio>
#include <cstring>

const int N = 5;
const int maxn = 30005;
const int coin[N] = {1, 5, 10, 25, 50};

typedef long long ll;

ll f[maxn];

void init () {

	for(int i = 1; i < maxn; i++)
		f[i] = 0;

	f[0] = 1;
	for (int i = 0; i < N; i++)
		for (int j = coin[i]; j < maxn; j++) {

			f[j] += f[j - coin[i]];
		}
}

int main () {

	int n;
	init();
	while (scanf ("%d", &n) != EOF) {

		if (f[n] == 1)
			printf ("There is only 1 way to produce %d cents change.\n", n);
		else
			printf ("There are %lld ways to produce %d cents change.\n", f[n], n);
	}
	return 0;
}
