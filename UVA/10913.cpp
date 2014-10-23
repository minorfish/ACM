#include <cstdio>
#include <cstring>

typedef long long ll;

const int N = 80;
const int M = 3;
const ll INF = 0x3f3f3f3f3f; 
const int dir[M][2] = {{0, -1}, {1, 0}, {0, 1}};

int G[N][N];
ll dp[N][N][6][M];
int n, k;

ll Max (const ll a, const ll b) { return a > b ? a: b;}

void init () {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int l = 0; l <= k; l++)
				for (int m = 0; m < M; m++)
					dp[i][j][l][m] = -INF;

	if (G[0][0] < 0)
		k--;
	for (int l = 0; l <= k; l++)
		for (int m = 0; m < M; m++)
			dp[n - 1][n - 1][l][m] = G[n - 1][n - 1];
}

ll DP (int x, int y, int d, int cnt) {

	int newx, newy;
	ll &ans = dp[x][y][cnt][d];
	if (ans != -INF)
		return ans;

	ll temp;
	if (d == 1) {

		for (int i = 0; i < M; i++) {
	
			newx = x + dir[i][0];
			newy = y + dir[i][1];
			if (newx < 0 || newx >= n || newy < 0 || newy >= n)
				continue;

			if (G[newx][newy] < 0 && cnt == k)
				continue;
			if (G[newx][newy] < 0 && cnt < k) {
				temp = DP(newx, newy, 2 - i, cnt + 1); 
				if (temp != -INF - 1)
					ans = Max (ans, temp + G[x][y]); 
			}
			if (G[newx][newy] >= 0) {
				temp = DP (newx, newy, 2 - i, cnt);
				if (temp != -INF - 1)
					ans = Max (ans, temp + G[x][y]);
			}
		}
	} else {

		for (int i = (d + 1) % M; i != d; i = (i + 1) % M) {

			newx = x + dir[i][0];
			newy = y + dir[i][1];
			if (newx < 0 || newx >= n || newy < 0 || newy >= n)
				continue;

			if (G[newx][newy] < 0 && cnt == k)
				continue;
			if (G[newx][newy] < 0 && cnt < k) {
				temp = DP(newx, newy, 2 - i, cnt + 1); 
				if (temp != -INF - 1)
					ans = Max (ans, temp + G[x][y]); 
			}
			if (G[newx][newy] >= 0) {
				temp = DP (newx, newy, 2 - i, cnt);
				if (temp != -INF - 1)
					ans = Max (ans, temp + G[x][y]);
			}
		}
	}

	if (ans == -INF)
		ans = -INF - 1;
	return ans;
}

int main () {

	int cas = 0;
	while (scanf ("%d%d", &n, &k), n || k) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf ("%d", &G[i][j]);

		init ();

		ll ans; 
		ans = DP(0, 0, 1, 0);

		printf ("Case %d:", ++cas);
		if (ans == -INF - 1)
			printf (" impossible\n");
		else
			printf (" %lld\n", ans);		
	}
	return 0;
}
