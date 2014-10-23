#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
int n;
int num[maxn], m;
int Num[maxn][35], cnt[35];
int t[35];

void init () {

	t[0] = 1;
	for (int i = 1; i <= 30; i++)
		t[i] = t[i - 1] * 2;
}

bool judge () {

	ll Sum = 0;
	for (int i = 0; i <= 30; i++) 
		if (cnt[i])
			Sum += t[i];

	if (Sum < m)
		return true;
	return false;
}

ll solve () {

	ll ans = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 30; i >= 0; i--) {
			if (num[k] >= t[i]) {
				Num[k][i] = 1;
				num[k] -= t[i];
			} else
				Num[k][i] = 0;
		}
	}

	int head, tail;
	head = tail = 1;

	for (int i = 0; i <= 30; i++)
		cnt[i] = 0;

	ll tmp; 
	while (tail <= n) {

		for (int i = 0; i <= 30; i++)
			if (Num[tail][i])
				cnt[i]++;

		if (!judge()) {	
			while (head <= tail && !judge()) {
				for (int i = 0; i <= 30; i++)
					if (Num[head][i])
						cnt[i]--;
				head++;
			}
		}
		ans += tail - head  + 1;
		tail++;
	}

	return ans;
}

int main () {

	int T;
	scanf ("%d", &T);
	init();
	for (int cas = 1; cas <= T; cas++) {

		printf ("Case #%d: ", cas);
		scanf ("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf ("%d", &num[i]);
		printf ("%I64d\n", solve());
	}
	return 0;
}
