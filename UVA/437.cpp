#include <cstdio>
#include <cstring>

const int N = 95;
typedef long long ll;

int n;
int G[N][N];
ll dp[N][N];

struct BLOCK { 

	int x, y, z;
}b[N];

bool judge (int i, int j) {

	if (b[i].x > b[j].x && b[i].y > b[j].y)
		return true;
	if (b[i].y > b[j].x && b[i].x > b[j].y)
		return true;
	return false;
}

void handle () {

	memset (G, 0, sizeof (G));
	for (int i = 0; i < 3 * n; i++)
		for (int j = 0; j < 3 * n; j++) {
		
			if (i != j && judge(i, j))
				G[i][j] = 1;
		}
}

ll Max (const ll a, const ll b) { return a > b? a: b; }

int DP (int x1, int y1) {

	ll& ans = dp[x1][y1];
	if (ans != -1)
		return ans;
	for (int i = 0; i < 3 * n; i++) {

		if (y1 == i)
			continue;
		if (G[y1][i])
			ans = Max (ans, DP(y1, i) + b[x1].z);	
	}

	if (ans == -1)
		ans = b[y1].z + b[x1].z;
	return ans;
}

int main () {

	int x, y, z;
	int cas = 0;
	ll ans;
	while (scanf ("%d", &n), n) {

		for (int i = 0; i < 3 * n; i = i + 3) {

			scanf ("%d%d%d", &b[i].x, &b[i].y, &b[i].z);
			b[i + 1].z = b[i].x;
			b[i + 1].y = b[i].y;
			b[i + 1].x = b[i].z;
			b[i + 2].z = b[i].y;
			b[i + 2].x = b[i].x;
			b[i + 2].y = b[i].z;	
		}

		handle();

		ans = 0;
		memset (dp, -1, sizeof (dp));
		for (int i = 0; i < 3 * n; i++)
			for (int j = 0; j < 3 * n; j++)
				if (G[i][j])
					ans = Max (ans, DP(i, j));
		printf ("Case %d: maximum height = %lld\n", ++cas, ans);
	}
	return 0;
}
