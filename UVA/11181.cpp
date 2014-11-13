#include <cstdio>
#include <cstring>

const int maxn = 25;

int N, K;
int vis[maxn];
double p[maxn];

double dfs (int k, int cnt, int b) {

	if (k == cnt) {

		double tmp = 1.0;
		for (int i = 0; i < N; i++)
			if (!vis[i])
				tmp *= (1.0 - p[i]);
		return tmp;
	}

	double ans = 0;
	for (int i = b; i < N; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			ans += dfs(k + 1, cnt, i + 1) * p[i]; 
			vis[i] = 0;
		}
	}
	return ans;
}

int main () {

	int cas = 0;
	while (scanf ("%d%d", &N, &K) && (N || K)) {

		for (int i = 0; i < N; i++)
			scanf ("%lf", &p[i]);

		printf ("Case %d:\n", ++cas);
		double pb = dfs(0, K, 0);
		double pa;
		for (int i = 0; i < N; i++) {
			vis[i] = 1;
			pa = dfs (0, K - 1, 0) * p[i];	
			printf ("%.6lf\n", pa/pb);
			vis[i] = 0;
		}
	}
	return 0;
}
