#include <cstdio>
#include <cstring>

const int maxn = 105;
const int maxm = 10;

int K, N;
double p[maxn][maxm];

void init () {

	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxm; j++)
			p[i][j] = -1.0;
}

double dp(int n, int k) {

	double& ans = p[n][k];			
	if (ans != -1)
		return ans;
	
	if (n == N)
		return ans = 1.0;
	
	ans = dp(n + 1, k);
	if (k - 1 >= 0)
		ans += dp(n + 1, k - 1);   
	if (k + 1 <= K)
		ans += dp(n + 1, k + 1);
	ans *= 1.0/(K + 1);
	return ans;
}

int main () {

	while (scanf ("%d%d", &K, &N) != EOF) {

		init();
		double ans = 0;
		for (int i = 0; i <= K; i++)
			ans += dp(1, i);
		printf ("%.5lf\n", ans * 100.0/(K + 1));
	}
	return 0;
}
