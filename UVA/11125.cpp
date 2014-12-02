#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 4500;
const int maxs = 5;
const int maxc = 5;

int N, PS, PC;
int num[maxc];
int f[maxn][maxs][maxc][maxs][maxc];

int dp (int state, int s, int c) {

	int& ans = f[state][PS][PC][s][c];
	if (ans != -1)
		return ans;

	if (!state) {
		if (PS != s && PC != c)
			return ans = 1; 
		return ans = 0;		
	}

	int tmp[maxc];
	int tS = state;
	for (int i = N - 1; i >= 0; i--) {

		if (tS >= (1<<(3*i))) {
			tmp[i] = tS/(1<<(3*i));
			tS %= (1<<(3*i));
		} else
			tmp[i] = 0;
	}

	ans = 0;
	for (int i = 0; i < N; i++) {
		if (i == c)
			continue;
		for (int j = 1; j <= min(3, tmp[i]); j++) {	
			if (j == s)
				continue;
			ans += dp(state - (j * (1<<(3*i))), j, i);
		}
	}
	return ans;
}

void solve () {

	scanf ("%d", &N);
	for (int i = 0; i < N; i++)
		scanf ("%d", &num[i]);

	int state = 0;
	for (int i = 0; i < N; i++)
		state += num[i] * (1<<(3*i));  

	int ans = 0;
	if (state) {
		for (int c = 0; c < N; c++)
			for (int s = 1; s <= min(num[c], 3); s++) {
				PS = s;
				PC = c;
				ans += dp(state - s * (1<<(3*c)), s, c);
			}
	} else
		ans = 1;
	printf ("%d\n", ans);
}

int main () {

	int T;
	scanf ("%d", &T);
	memset (f, -1, sizeof(f));

	while (T--) {
		solve();		
	}
	return 0;
}
