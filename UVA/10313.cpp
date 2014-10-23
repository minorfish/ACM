#include <cstdio>
#include <cstring>

const int N = 305;
typedef long long ll;
ll dp[N][N];

int Min (const int a, const int b) { return a < b ? a: b; }

void init () {

	dp[0][0] = 1;
	for (int i = 1; i <= 300; i++) {
		for (int j = i; j <= 300; j++) {
			for (int k = 0; k <= j - i; k++)
				dp[j][k + 1] += dp[j - i][k];
		}
	}
}

int main () {

	int n, l1, l2;
	int x;
	char ch;
	init ();
	while (scanf ("%d", &n) != EOF) {

		scanf ("%c", &ch);
		l1 = 0;
		l2 = 300;
		if (ch != '\n') {

			scanf ("%d%c", &x, &ch);
			if (ch != '\n') {
				l1 = x;
				scanf ("%d", &l2);
			} else
				l2 = x;
		}

		if (l1 <= 300) {

			if (l2 > 300)
				l2 = 300;
			ll ans = 0;
			for (int i = l1; i <= l2; i++)	
			ans += dp[n][i];
			printf ("%lld\n", ans);
		} else 
			printf ("0\n");
	}
	return 0;
}
