#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1005;
const int M = 15;
const int maxn = 255;

int Milk[N][M];
int cnt[N];
int vis[N];
int survice[N];
int n;

int gcd (int a, int b) {

	return b == 0 ? a : gcd (b, a % b);
}

int f() {

	int T = 1;
	int tmp;
	for (int i = 0; i < n; i++) {
		if (vis[i])
			continue;
		if (T > cnt[i])
			tmp = gcd(T, cnt[i]);
		else
			tmp = gcd(cnt[i], T);
		T = T * cnt[i] / tmp;
	}
	return T;
}

int solve () {

	int T = f();
	memset (vis, 0, sizeof (vis));
	//	memset (survice, -1, sizeof (survice));
	survice[n] = 0;
	int num = n;
	for (int p = 0;; p++) {

		bool flag = 0;
		for (int i = 1; i <= T; i++) {

			int minnum = maxn;
			int tmp = 0;
			for (int j = 0; j < n; j++) {

				if (vis[j]) 
					continue;
				int d = (i % cnt[j]) == 0 ? cnt[j] : (i % cnt[j]);
				if (minnum > Milk[j][d]) {
					minnum = Milk[j][d];
					tmp = j;
				} else if (minnum == Milk[j][d])
					tmp = -1;	
			}

			if (tmp != -1) {
				vis[tmp] = 1;
				num--;
				survice[num] = p * T + i;;
				flag = 1;
			}
		}
		if (!flag)
			return num;
	}
}

int main () {

	int cas, d;
	scanf ("%d", &cas);
	while (cas--) {

		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {

			scanf ("%d", &cnt[i]);
			for (int j = 1; j <= cnt[i]; j++)
				scanf ("%d", &Milk[i][j]);
		}
		int ans = solve();
		printf ("%d %d\n", ans, survice[ans]);
	}
	return 0;
}

