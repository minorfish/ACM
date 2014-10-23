#include <cstdio>
#include <cstring>

const int N = 1000005;
const int M = 25;
int visit[M];
int v[N];
int dp[N];
int n, k;

int Max (const int a, const int b) { return a > b? a: b; }

void init () {

	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		dp[i] = -1;
}

bool printf_ans (int m, int l) {

	if (!m) 
		return true;
	for (int i = l; i < k; i++)		
		if (m - v[i] >= 0 && dp[m - v[i]] != -1) {
			
			visit[i] = 1;
			if (printf_ans (m - v[i], i + 1))
				return true;
			visit[i] = 0;
		}
	return false;	
}

int main () {

	while (scanf ("%d", &n) != EOF) {

		scanf ("%d", &k);
		for (int i = 0; i < k; i++)
			scanf ("%d", &v[i]);

		init ();		
		for (int i = 0; i < k; i++)
			for (int j = n; j >= v[i]; j--) {
					
					if (dp[j - v[i]] != -1)
						dp[j] = Max (dp[j - v[i]] + 1, dp[j]); 
				}
	
		int i;
		for (i = n; i >= 0; i--)
			if (dp[i] != -1)
				break;

		memset (visit, 0, sizeof (visit));
		printf_ans(i, 0);

		for (int j = 0; j < k; j++)
			if (visit[j])
				printf ("%d ", v[j]);
		printf ("sum:%d\n", i);
	}
	return 0;
}
