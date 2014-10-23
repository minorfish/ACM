#include <cstdio>
#include <cstring>

const int maxn = 1<<17;
const int M = 20;

int dp[maxn];
int n, k;
int tree[M][2];
int line[M][M];

bool judge (int i, int j, int k) {

	int a = (tree[j][1] - tree[i][1]) * (tree[k][0] - tree[j][0]);
	int b = (tree[k][1] - tree[j][1]) * (tree[j][0] - tree[i][0]);
	return a == b ? true : false;
}

int Min (const int a, const int b) { return a < b ? a: b; }

void init () {

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			line[i][j] = 0;
			for (int l = 0; l < n; l++) {
				
				if (judge (i, j, l)) {
					line[i][j] |= (1<<l);
				}
			}
		}
	}

	for (int i = 0; i <= (1<<n); i++)
		dp[i] = M;
}

int count (int s) {
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (s & (1<<i))
			ans++;
	return ans;
}

int DP (int s) {

	int& ans = dp[s];

	if (ans != M)
		return ans;
	if (count (s) >= k)
		return ans = 0; 

	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (((1 << i) & s) == 0) {
			for (int j = i + 1; j < n; j++) {
				if (((1 << j) & s) == 0) {
					flag = 1;
					ans = Min (ans, DP(s | line[i][j]) + 1);
					//printf ("%d %d %d\n", s, s | line[i][j], ans);
				}
			}
			if (!flag) { 
				ans = Min (ans, DP(s | (1<<i)) + 1);
			}
		}
	}
	return ans;
}

int main () {
	
	int t;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {

		scanf ("%d%d", &n, &k);
		for (int j = 0; j < n; j++)
			scanf ("%d%d", &tree[j][0], &tree[j][1]);

		init ();
		printf ("Case #%d:\n", i);
		printf ("%d\n", DP(0));	
		if (i != t)
			printf ("\n");
	}
	return 0;
}
