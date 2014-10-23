#include <cstdio>
#include <cstring>

const int N = 1005;
const int M = 4;
const char type[M][15] = {"SIMPLE", "FULLY-GROWN", "MUTAGENIC", "MUTANT"};

char str[N];
int dp[N][N];

int judge1 (int i, int j) {

	if (str[i] == 'A' && str[j] == 'B')
		return 1;
	return 0;
}

int judge2 (int i, int j) {
	
	if (str[i] == 'B' && str[j] == 'A')
		return 1;
	return 0;
}

int Min (const int a, const int b ) { return a < b ? a: b; }

int main () {

	int t;
	int len;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%s", str);
		len = strlen (str);

		for (int i = 1; i <= len; i++)
			if (str[i - 1] == 'A')
				dp[i][i] = 0;
			else 
				dp[i][i] = 3;

		for (int i = 1; i <= len; i++)
			for (int j = i + 1; j <= len; j++)
				dp[i][j] = 3;

		for(int l = 2; l < len; l += 2)
			for (int i = 1; i + l <= len; i++) {
				
				dp[i][i + l] = 3; 
				if (dp[i][i + l - 2] != 3 && judge1 (i + l - 2, i + l - 1))
					dp[i][i + l] = Min (dp[i][i + l], 1);
				if (dp[i + 1][i + l - 1] != 3 && judge2 (i - 1, i + l - 1))
					dp[i][i + l] = Min (dp[i][i + l], 2);
			}

		printf ("%s\n", type[dp[1][len]]);		
	}
	return 0;
}
