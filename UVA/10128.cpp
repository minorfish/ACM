#include <cstdio>
#include <cstring>

typedef long long ll;
const int maxn = 15;

ll f[maxn][maxn][maxn];

int main () {

	int T;
	int N, P, R;
	scanf ("%d", &T);
	while (T--) {

		memset (f, 0, sizeof (f));
		scanf ("%d%d%d"	, &N, &P, &R);

		f[1][1][1] = 1;
		for (int i = 2; i <= N; i++)
			for (int j = 1; j <= i; j++)
				for (int k = 1; k <= i; k++) {
					f[i][j][k] = (i - 2) * f[i - 1][j][k] + f[i - 1][j - 1][k] + f[i - 1][j][k - 1];		
				}
		printf ("%lld\n", f[N][P][R]);
	}
	return 0;
}
