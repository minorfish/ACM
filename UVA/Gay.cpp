#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
int p[maxn], cnt[maxn];
int N;

map<string, int> vis;

void init () {

	N = 0;
	vis.clear();
	for (int i = 1; i < maxn; i++) {

		p[i] = i;
		cnt[i] = 1;
	}
}

int hash (string str) {

	if (!vis[str])
		vis[str] = ++N;
	return vis[str];
}

int getParent (int x) {
	
	return x == p[x] ? x : p[x] = getParent(p[x]);
}

int main () {

	int T;
	int n;
	int x, y;
	char str[100];

	scanf ("%d", &T);
	while (T--) {

		scanf ("%d", &n);
		init();

		for (int i = 0; i < n; i++) {

			scanf ("%s", str);
			x = hash(str);
			scanf ("%s", str);
			y = hash(str);
			
			int q1 = getParent (x);
			int q2 = getParent (y);
			if (q1 != q2) {
				
				p[q1] = q2;
				cnt[q2] += cnt[q1];
			}
		}

		int ans = 0;
		for (int i = 1; i <= N; i++) {

			if (p[i] == i && cnt[i] != 1)
				ans = max(ans, cnt[i]);	
		}

		printf ("%d\n", ans);
	}
	return 0;
}
