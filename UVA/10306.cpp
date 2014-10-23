#include <cstdio>
#include <cmath>
#include <cstring>


const int N = 45;
const int maxn = 305;
const int INF = 0x3fffffff;

int value[N][2];
int dp[maxn][maxn];
int n, s;

int Min (const int a, const int b) { return a < b ? a: b; }

void init () {

	for (int i = 0; i <= s; i++)
		for (int j = 0; j <= s; j++)
			dp[i][j] =	INF;

	for (int i = 0; i < n; i++)
		dp[value[i][0]][value[i][1]] = 1;
	
/*	printf ("%d\n", s);
	for (int i = 0; i <= s; i++) {

		for (int j = 0; j <= s; j++)
			printf ("%d ", dp[i][j]);
		printf ("\n");
	}*/	
}

int DP (int x, int y) {

	int& ans = dp[x][y];  
	if (ans != INF)
		return ans;
	int x1, y1;
	for (int i = 0; i < n; i++) {
		
		x1 = value[i][0];
		y1 = value[i][1];
		if (x >= x1 && y >= y1)		
			ans = Min (ans, DP(x - x1, y - y1) + 1); 	
	}
	
	if (ans == INF)
		ans = INF + 1;  
	return ans;	
}

int main () {

	int t;
	scanf ("%d", &t);
	int ans;
	while (t--) {

		scanf ("%d%d", &n, &s);
		for (int i = 0; i < n; i++) 
			scanf ("%d%d", &value[i][0], &value[i][1]);
		
		init ();
		
		ans = INF;
	
		int y;
		for (int x = 0; x <= s; x++) {
			
			y = (int) sqrt (s * s - x * x);	
			if (y * y + x * x == s * s) 		
				ans = Min (ans, DP(x, y));
		}

		if (ans == INF)
			printf ("not possible\n");
		else
			printf ("%d\n", ans);
	}
	return 0;
}

