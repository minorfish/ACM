#include <stdio.h>
#include <string.h>

const int N = 105;
int n, m, s[N][N], ans[N], cas, count, vis[N];

bool judge (int x, int num) {

	for (int i = 1; i <= num; i++)
		if (s[x][vis[i]])
			return 1;
	return 0;
}

void solve (int num, int x) {
	
	vis[num] = x;
	for (int i = x + 1; i <= n; i++) {
		
		if (judge (i, num))
			continue;
		solve (num + 1, i);
	}

	if (num >= count) {
			
		count = num;
		memcpy (ans, vis, sizeof (vis));
	}
}

int main () {

	scanf ("%d", &cas);
	while (cas--) {

		scanf ("%d%d", &n, &m);
		memset (s, 0, sizeof(s));
		count = -1;
		int x, y;
		for (int i = 0;  i < m; i++) {
			
			scanf ("%d%d", &x, &y);
			s[x][y] = s[y][x] = 1;
		}
		for (int i = 1; i <= n; i++) {

			memset (vis, 0, sizeof (vis));
			solve (1, i);
		}
		printf ("%d\n", count);
		for (int i = 1; i < count; i++)
				printf ("%d ", ans[i]);
		printf ("%d\n", ans[count]);
	}
	return 0;
}
