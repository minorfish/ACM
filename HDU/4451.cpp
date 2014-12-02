#include <cstdio>
#include <cstring>

const int maxn = 1e3 + 5;
int vis1[maxn][maxn], vis2[maxn][maxn];
int c[maxn], s[maxn];

int main () {

	int N, M, K, P;
	int a, b;
	char str1[10], str2[10];
	while (scanf ("%d%d%d", &N, &M, &K) && (N || M ||K)) {
	
		memset (vis1, 0, sizeof (vis1));
		memset (vis2, 0, sizeof (vis2));
		memset (c, 0, sizeof (c));
		memset (s, 0, sizeof (s));

		scanf ("%d", &P);
		for (int i = 0; i < P; i++) {
			scanf ("%s%d%s%d", str1, &a, str2, &b);
			if (str1[0] == 'c' && str2[0] == 'p') {

				if (!vis1[a][b]) {
					vis1[a][b] = 1;
					c[b]++;
				}
			}

			if (str1[0] == 'p' && str2[0] == 's') {
				if (!vis2[a][b]) {
					vis2[a][b] = 1;
					s[a]++;
				}
			}
		}
	
		int ans = 0;
		for (int i = 1; i <= M; i++)
			ans += (N - c[i]) * (K - s[i]);
		printf ("%d\n", ans);
	}
	return 0;
}
