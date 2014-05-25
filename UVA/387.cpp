#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

const int N = 10;
const int M = 4;

char str[N * 2];
int n, m, ans[M][M], i_count;
map <string, int> vis;

struct SQ {

	int s[M][M];
	int r, c;
} sq[N];

void handle (int k ) {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)  {

			sq[k].s[i][j] = (str[t++] - '0') * k;
			if (sq[k].s[i][j]  == '1')
				i_count++;
		}
	sq[k].r = n;
	sq[k].c = m;
}

void init (int t) {

	memset (ans, -1, sizeof (ans));
	for (int i = 1; i <= t; i++) {

		scanf ("%d%d", &n, &m);
		for (int j = 0; j < n; j++)
			scanf ("%s", &str[m *j]);
		str[m * n] = '\0';
		handle (i);
		if (!vis[str])
			vis[str] = t;
	}
}

void dfs (int cur, int t) {

	if (cur == 1) {
		for (int k = 1; k <= t; k++) {
			
			for (int i = 0; i + sq[cur].c < M ; i++)
				for (int j = 0; j + sq[cur].r < M; j++) {

					memcpy (
				}
		}
	}
}


int main () {

	int n, m, t;
	while (scanf ("%d", &t), t) {

		init (t);
		if (i_count == M * M)
			dfs(1);
		else

	}
	return 0;
}
