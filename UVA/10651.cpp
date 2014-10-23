#include <cstdio>
#include <cstring>

const int N = 12;
const int maxn = 1 << N;

int dp[maxn];

void init () {

	for (int i = 0; i < maxn; i++)
		dp[i] = N + 1;
}

int Min (const int a, const int b) { return a < b ? a: b; }

int d (int n) {

	if (dp[n] != N + 1)
		return dp[n];

	int t;
	for (int i = 0; i < N - 2; i++) {
		 
		t = n;
		if ((n & (1 << i)) && (n & (1 << (i + 1))) && ! (n & (1 << (i + 2)))) {

		  t &= ~(1 << i);
		  t &= ~(1 << (i + 1));
		  t |= 1 << (i + 2);
		  dp[n] = Min (dp[n] , dp[t] = Min (dp[t], d(t)));
		} else if (!(n & (1 << i)) && (n & (1 << (i + 1))) && (n & (1 << (i  + 2)))) {

		  t |= 1 << i;
		  t &= ~(1 << (i + 1));
		  t &= ~(1 << (i + 2));
		  dp[n] = Min (dp[n], dp[t] = Min (dp[t], d(t)));
				}
	}
	
	int cnt = 0;
	for (int i = 0; i < N; i++)
		if (n & (1 << i))
			cnt++;
	return dp[n] = Min(dp[n], cnt);
}

int main () {

	int t;
	int n;
	char ch;
	scanf ("%d%*c", &t);
	init ();
	while (t--) {

		n = 0;
		for (int i = 0; i < N; i++) {

			scanf ("%c", &ch); 
			if (ch == 'o')
				n = n | (1 << i);	
		}
		getchar();
		printf ("%d\n", d(n));
	}
	return 0;
}
