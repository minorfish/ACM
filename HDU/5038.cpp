#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int N = 1e6 + 5;
const int M = 105;
int vis[M];

struct Grade {

	int num;
	int cnt;
}G[N];

int cmp (const Grade &a, const Grade &b) {

	if (a.cnt == b.cnt)
		return a.num > b.num;
	return a.cnt > b.cnt;
}

int main () {

	int T;
	int num, n;
	scanf ("%d", &T);
	for (int cas = 1; cas <= T; cas++) {

		printf ("Case #%d:\n", cas);
		memset (vis, 0, sizeof (vis));
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &num);
			vis[abs(num - 100)]++;
		}
	
		int tmp = 0;
		for (int i = 0; i <= 100; i++) {

			if (vis[i]) {

				G[tmp].num = i;
				G[tmp++].cnt = vis[i];
			}
		}
		
		sort (G, G + tmp, cmp);
	
		if (tmp > 1 && G[0].cnt == G[tmp - 1].cnt)
			printf ("Bad Mushroom\n");
		else {
			int ans = G[0].cnt;
			printf ("%d", 10000 - G[0].num * G[0].num);
			for (int i = 1; i < tmp; i++) {
				if (G[i].cnt == ans)
					printf (" %d", 10000 - G[i].num * G[i].num);
				else
					break;
			}
			printf ("\n");
		}
	}
		
	return 0;
}
