#include <cstdio>
#include <cstring>

const int maxn = 25005;
const int maxnL = 20;

char word[maxn][maxnL];
int n;
int l[maxn];
int dp[maxn];
int kind[maxnL][maxn]; 
int c[maxnL];

int Max (const int a, const int b) { return a > b? a: b; }

bool j_del (int a, int b) {

	int flag = 0;
	for (int i = 0, j = 0; i < l[b]; i++) {

		if (word[b][i] != word[a][j]) {

			if (flag)
				return false;
			else
				flag = 1;
			continue;
		}
		j++;
	}
	if (flag)
		return true;
	return false;
}

bool judge (int a, int b) {

	if (l[a] == l[b]) {
			
		int flag = 0;
		for (int i = 0; i < l[a]; i++) {
			if (word[a][i] != word[b][i]) {
				if (flag)
					return false;
				else
					flag = 1;
			}
		}
		if (flag)
			return true;
		return false;

	} else if (l[a] == l[b] + 1) 
		return j_del(b, a);
	else if (l[b] == l[a] + 1) 
		return j_del(a, b);
	else
		return false;
}

void search (int len, int i) {	

	for(int j = 0; j < c[len]; j++) 	
		if(i > kind[len][j] && judge (kind[len][j], i)) { 
			dp[i] = Max (dp[i], dp[kind[len][j]] + 1);
		}
}

void handle () {

	for (int i = 1; i < n; i++) {

		search (l[i] - 1, i);
		search (l[i], i);
		search (l[i] + 1, i);
/*		for (int j = 1; j < i; j++) 
			if (judge(j, i))
				dp[i] = Max (dp[i], dp[j] + 1);*/
	}
}

int main () {

	n = 1;
	memset (c, 0, sizeof (c));
	while (gets(word[n]) != NULL) {
		l[n] = strlen (word[n]);
		kind[l[n]][c[l[n]]++] = n;
		n++;
	}

	for (int i = 1; i < n; i++)
		dp[i] = 1;

	handle ();

	int ans = 0;
	for (int i = 1; i < n; i++) 
		ans = Max (ans, dp[i]);

	printf ("%d\n", ans);
	return 0;
}
