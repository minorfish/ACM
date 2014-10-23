#include <cstdio>
#include <cstring>

const int N = 11;
const int maxn = 30005;
const int c[N] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

typedef long long ll;

ll f[maxn];

void  init () {

	memset (f, 0, sizeof (f));
	f[0] = 1;
	for (int i = 0; i < N; i++)
		for (int j = c[i]; j <= maxn - 5; j++)
			f[j] += f[j - c[i]];
}

int main () {
	
	init();
	float num;
	int n;
	while (1) {
		scanf ("%f", &num);
		n = (num + 0.005) * 100;
		if (!n)
			break;
		printf ("%6.2f%17lld\n", num, f[n]);
	}
	return 0;
}
