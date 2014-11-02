#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e3 + 5;
int vis[maxn];

int n;
struct homework {

	int deadt, score;
}h[maxn];

int cmp (const homework &a, const homework &b) {

	if (a.score != b.score)
		return a.score > b.score;
	return a.deadt < b.deadt;
}

int solve () {

	sort(h, h + n, cmp);
	memset (vis, -1, sizeof (vis));

	int ans = 0, time;
	for (int i = 0; i < n; i++) {

		time = h[i].deadt - 1;
		if (time >= n)
			continue;
		while (time >= 0 && vis[time] != -1) {
			time--;
		}
		
		if (time >= 0)
			vis[time] = 1;
		else
			ans += h[i].score;
	}
	return ans;
}

int main () {
	
	int T;
	scanf ("%d", &T);
	while (T--) {
		
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			scanf ("%d", &h[i].deadt);
		for (int i = 0; i < n; i++)
			scanf ("%d", &h[i].score);

		printf ("%d\n", solve());	
	}
	return 0;
}
