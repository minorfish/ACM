#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int M = 7e4;
const int N = 20;

#define lowbit(x) ((x)&(-x))
typedef long long ll;

int n;
int t[N], C[N][M];

void add (int k, int x, int v) {

	while (x < M) {
		
		C[k][x] += v;
		x += lowbit(x);
	}
}

ll sum (int k, int x) {

	int ret = 0;
	while(x > 0) {
		
		ret += C[k][x];
		x -= lowbit(x);
	}
	return ret;
}

void init () {
	
	t[0] = 1;
	for (int i = 1; i < N; i++)
		t[i] = t[i - 1] * 2;
}

void handle (int num) {

	for (int i = N - 1; i >= 0; i--) {

		add(i, num + 1, 1);
		if (num >= t[i])
			num -= t[i];
	}
}

ll solve () {

	ll ans = 0;
	int addnum = 0;
	char str[10];
	int x, l, r;

	while (scanf ("%s", str) && str[0] != 'E') {
		
		scanf ("%d", &x);
		if (str[0] == 'C')
			addnum = (addnum + x) % t[16];
		else {			
			if (addnum & t[x]) {

				l = t[x + 1] + t[x] - addnum % t[x + 1];
				r = min(t[x + 2] - 1 - addnum % t[x + 1], t[16] - 1);
				ans += sum (x, r + 1) - sum (x, l);
			}

			l = t[x] - addnum % t[x + 1];
			r = t[x + 1] - 1 - addnum % t[x + 1];
			ans += sum (x, r + 1) - sum (x, l);
//			printf("%d %d %lld\n", min, max, ans);
		}
	}
	return ans;
}

int main () {

	init();
	int cas = 0, num;
	while (scanf ("%d", &n) && n != -1) {

		memset (C, 0, sizeof (C));	
		for (int i = 0; i < n; i++) {
			scanf ("%d", &num);
			handle(num);
		}
		printf ("Case %d: %lld\n", ++cas, solve());
	}
	return 0;
}
