#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 1500;
const double esp = 1e-9;

double f[maxn][maxn];
double P[maxn][maxn];

int n, m;

void init () {

	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= (1<<n); j++)
			f[i][j] = -1;

}

double dp(int k, int st) {

	double &ans = f[k][st];

	if (fabs(ans + 1) > esp)
		return ans;

	if (k == m)
		return ans = 0;

	double tmp;
	for (int i = 0; i < n; i++) {

		if (st & (1<<i))
			continue;
		if ((st | (1<<i)) == (1<<n) - 1)
			tmp = dp(k + 1, 0);
		else
			tmp = dp(k + 1, st |(1<<i));

		if (tmp >= 0)
			ans = max(ans, tmp + P[i][k]);
	}

	if (ans < 0)
		ans = -2;
	return ans;	
}

int main () {

	int T;
	scanf ("%d", &T);

	for (int cas = 1; cas <= T; cas++) {

		scanf ("%d%d", &n, &m);						
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf ("%lf", &P[i][j]);

		init();

		printf ("Case #%d: %.5lf\n", cas, dp(0, 0));
	}
	return 0;	
}
