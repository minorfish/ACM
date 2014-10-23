#include <cstdio>
#include <cstring>

const int INF = 0x3f3f3f3f;
const int N = 105;
const int M = 8;
const int maxn = 1<<(2 * M);

int s, m, n;

int T[N][M];
int num[N];
int cost[N];
int dp[maxn][N];
int v[M + 1];
int mm, sum;

int Min (const int a, const int b) { return a < b? a: b;}

void init (int st) {

	for (int i = st; i < mm; i++)
		for (int j = 1; j <= n + 1; j++)
			dp[i][j] = INF;
	for (int i = 1; i <= n + 1; i++)
		dp[mm][i] = 0;
}

int DP (int st, int k) {

	int& ans = dp[st][k];

	if (ans != INF)
		return ans;
	if (k <= n) {
	
		int newst = st;
		for (int j = 0; j < num[k]; j++) {

			if (newst & (1 << (T[k][j] - 1))) {
				newst |= (1 << (T[k][j] - 1 + s));
				newst &= ~(1 << (T[k][j] - 1));
			} else if (!(newst & (1 << (s + T[k][j] - 1))))	
				newst |= (1 << (T[k][j] - 1)); 
		}
		//	printf ("%d %d\n", st , newst);
		ans = Min (ans, Min (DP(newst, k + 1) + cost[k], DP(st, k + 1)));
	}

	if (ans == INF)
		ans = INF + 1;
	return ans;
}

int main () {

	int st;
	int money, t;
	char ch;
	while (scanf ("%d%d%d", &s, &m, &n), s || m || n) {

		st = sum = 0;
		memset (v, 0, sizeof (v));
		for (int i = 1; i <= m; i++) {

			scanf ("%d", &money);
			sum += money;
			while (scanf ("%c", &ch)) {
				if (ch == '\n')
					break;
				if (ch >= '1' && ch <= '8') {

					if (v[ch - '0'] < 2) {
						v[ch - '0']++;
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {

			scanf ("%d", &cost[i]);
			t = 0;
			while (scanf ("%c", &ch)) {

				if (ch == '\n')
					break;
				if (ch >= '1' && ch <= '8') {

					T[i][t++] = ch - '0';	
				}
			}
			num[i] = t;
		}

		for (int i = 1; i <= s; i++)
			if (v[i])
				st += 1 << (i - 1 + (v[i] - 1) * s);

		mm = (1<<(2 * s)) - (1<<s);

		init (st);
		printf ("%d\n", DP(st, 1) + sum);
	}
	return 0;
}
