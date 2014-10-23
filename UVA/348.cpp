#include <cstdio>
#include <cstring>

typedef long long ll;

const int INF = 0x7fffffff;
const int N = 15;

ll A[N];
int n;
ll dp[N][N];

ll Min (const ll a, const ll b) { return a < b? a: b;}

void printf_ans (int s, int e) {

	if (s == e) {

		printf ("A%d", s);
		return;
	}
	for (int i = s; i < e; i++) {

		if ((dp[s][i] + dp[i + 1][e] + A[s - 1] * A[i] * A[e]) == dp[s][e]) {
		
			if (s != i)
				printf ("(");
			printf_ans(s, i);
			if (s != i)
				printf (")");
			printf (" x ");
			if (i + 1 != e)
				printf ("(");
			printf_ans(i + 1, e);
			if (i + 1 != e)
				printf (")");
			break;
		}
	}
}

int main () {

	int cas = 0;
	while (scanf ("%d", &n), n) {

		for (int i = 0; i < n; i++)
			scanf ("%lld%lld", &A[i], &A[i + 1]);
		
		for (int i = 1; i <= n; i++)
			dp[i][i] = 0;
		
		ll temp;
		for (int len = 1; len < n; len++)
			for (int i = 1; i + len <= n; i++) {
				
				temp = INF;
				for (int k = 0; k < len; k++)
					temp = Min (temp, dp[i][i + k] + dp[i + k + 1][i + len] + A[i - 1] * A[i + k] * A[i + len]);
				dp[i][i + len] = temp;
			}

//	    printf ("%lld\n", dp[1][n]);
		printf ("Case %d: (", ++cas); 
		printf_ans(1, n);	
		printf (")\n");
	}
	return 0;
}
