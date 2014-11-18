#include <cstdio>
#include <cstring>

typedef long long ll;
const int maxn = 75;

int N, T, P;
ll f[maxn][maxn];

void init () {
	memset (f, -1, sizeof(f));
}

ll dp(int k, int sum) {

	ll& ans = f[k][sum];
	if (ans != -1)
		return ans;

	if (k == N) {
		if (sum == T)
			return ans = 1;
		return ans = 0;
	}

	ans = 0;
	for (int i = P; i <= T - sum; i++) {
		
		if (i + sum <= T)
			ans += dp(k + 1, sum + i);
		else
			break;
	}
	
	return ans;
}

int main () {

	int K;
	scanf ("%d", &K);
	
	while (K--) {

		scanf ("%d%d%d", &N, &T, &P);
		init();
		printf ("%lld\n", dp(0, 0));
	}
	return 0;
}
