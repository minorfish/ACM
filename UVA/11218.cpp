#include <stdio.h>
#include <string.h>

const int N = 100;
int comb[N][3], score[N];
int n, vis[10], max;
bool flag;


void dfs (int cur, int k, int ans) {
	
	if (cur == 3) {
		
		int i;
		for (i = 1; i < 10; i++)
			if (!vis[i])
				break;
		if (i == 10) {

			flag = 1;
			if (max < ans)
				max = ans;
		}
		return;
	}

	for (int i = k; i < n; i++) {
	
		int j;
		for (j = 0; j < 3; j++) {

			if (vis[comb[i][j]])
				break;
		}
		if (j != 3)
			continue;
		vis[comb[i][0]] = vis[comb[i][1]] = vis[comb[i][2]] = 1;
		dfs (cur + 1, i + 1, ans + score[i]);
		vis[comb[i][0]] = vis[comb[i][1]] = vis[comb[i][2]] = 0;
	}
}

void init () {

	memset (vis, 0, sizeof (vis));
	max = -1;
	flag = 0;
}

int main () {
	
	int cas = 0;
	while (scanf ("%d", &n) , n) {
		
		init ();
		for (int i = 0; i < n; i++)
			scanf ("%d%d%d%d", &comb[i][0], &comb[i][1], &comb[i][2], &score[i]);
		dfs (0, 0, 0);
		printf ("Case %d: %d\n", ++cas, max);
	}
	return 0;
}
