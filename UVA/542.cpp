#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 16;
char name[maxn][maxn];
double p[maxn][maxn];
double f[maxn][maxn][maxn];
double esp = 1e-9;

void init () {

	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			for (int k = 0; k < maxn; k++)
				f[i][j][k] = -1.0;
}

double dp (int k, int l, int r) {

	double& ans = f[k][l][r];

	if (ans > 0)
		return ans; 
	if (r - l == 1)
		return ans = p[k][k == l?r:l];

	int m = (l + r)>>1;
	double tmp;
	ans = 0;

	if (k <= m) { 
		tmp = dp(k, l, m);	
		for (int i = m + 1; i <= r; i++)
			ans += p[k][i] *  tmp * dp(i, m + 1, r);
	} else {

		tmp = dp(k, m + 1, r);
		for (int i = l; i <= m; i++)
			ans += p[k][i] * tmp * dp(i, l, m);
	}
	return ans;
}

int main () {

	while (scanf ("%s", name[0]) != EOF) {

		for (int i = 1; i < maxn; i++)
			scanf ("%s", name[i]);
	
		int P;
		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++) {
				scanf ("%d", &P);
				p[i][j] = P/100.0;
			}

		init();
		for (int i = 0; i < maxn; i++)
			printf ("%-10s p=%.2lf%\n", name[i], dp(i, 0, maxn - 1) * 100.0);

	}
	return 0;
}
