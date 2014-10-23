#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long ll;
const int N = 20;

ll dp[N][N];
char str[N];
int len;

void init () {

	memset (dp, 0, sizeof (dp));
	for (int i = 0; i < len; i++)
		dp[0][i] = 1;
}

int translate (int i) {

	if (str[i]  >= '1' && str[i] <= '9')
		return str[i] - '1';
	else {

		switch (str[i]) {
			case 'A' : return 9;
			case 'B' : return 10;
			case 'C' : return 11;
			case 'D' : return 12;
			case 'E' : return 13;
			case 'F' : return 14;
		}
	}	
}

void handle (int i, int j) {

	for (int k = 0; k < len; k++) {
		if (abs (k - j) > 1) 
			dp[i][j] += dp[i - 1][k];		
	}
}

int main () {

	while (scanf ("%s" , str) != EOF) {

		len = strlen (str);
		init ();

		for (int i = 1; i < len; i++) {

			if (str[i - 1] == '?') {
				for (int j = 0; j < len; j++) 
					handle(i, j);

			} else {

				int k = translate (i - 1);
				for (int j = 0; j < len; j++) {

					if (abs (j - k) > 1)
						dp[i][j] += dp[i - 1][k];
				}
			}
		}

		ll ans;
		if (str[len - 1] != '?') 
			ans = dp[len - 1][translate(len - 1)];
		else {

			ans = 0;
			for (int i = 0; i < len; i++)
				ans += dp[len - 1][i];	
		}

		printf ("%lld\n", ans);
	}
	return 0;
}
