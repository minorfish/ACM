#include <cstdio>
#include <cstring>

typedef long long ll;
const int maxn = 205;
const int maxm = 15;
const int maxd = 25;

int N, Q, MOD, M;
int num[maxn], tmp[maxn];
ll f[maxn][maxm][maxd];

void init () {

	for (int i = 0; i < N; i++)
		scanf ("%d", &num[i]);	
}

ll dp (int n, int m, int d) {

	ll& ans = f[n][m][d];
	if (ans != -1)
		return ans;

	if (n == N) {

		if (m == M && d == 0)
			return ans = 1;
		return ans = 0;
	}

	ans = 0;
	if (m < M)
		ans += dp(n + 1, m + 1, (d + tmp[n]) % MOD);
	ans += dp(n + 1, m, d); 
	return ans;
}

int main () {

	int cas = 0;
	while (scanf ("%d%d", &N, &Q) && (N || Q)) {

		init();

		printf ("SET %d:\n", ++cas);
		for (int i = 0; i < Q; i++) {
			scanf ("%d%d", &MOD, &M);

			memset (f, -1, sizeof (f));
			for (int j = 0; j < N; j++)
				tmp[j] = (num[j] % MOD + MOD) % MOD;

			printf ("QUERY %d: %lld\n", i + 1, dp(0, 0, 0));
		}
	}
	return 0;
}
