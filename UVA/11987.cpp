#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 5;

int n, m;
int parent[maxn], cnt[maxn], sum[maxn];
int id[maxn];
int dex;

void init () {

	for (int i = 0; i <= n; i++) {

		cnt[i] = 1;
		sum[i] = id[i] = parent[i] = i;
	}
	dex = n;
}

int getParent (int a) {

	return a == parent[a] ? a: parent[a] = getParent (parent[a]);
}

void Union (int a, int b) {

	int p = getParent (a);
	int q = getParent (b);
	if (p != q) {

		parent[p] = q;
		cnt[q] += cnt[p];
		sum[q] += sum[p];
	}
}

void move (int a) {

	int p = getParent (id[a]);
	cnt[p]--;
	sum[p] -= a;
	id[a] = ++dex;
	parent[dex] = dex;
	cnt[dex] = 1;
	sum[dex] = a;  
}

int main () {

	int type;
	int a, b;
	while (scanf ("%d%d", &n, &m) != EOF) {

		init();
		while (m--) {

			scanf ("%d", &type);
			if (type == 1) {

				scanf ("%d%d", &a, &b);
				Union (id[a], id[b]);
			} else if (type == 2) {

				scanf ("%d%d", &a, &b);
				int p = getParent (id[a]);
				int q = getParent (id[b]);
				if (p != q) {

					move(a);
					Union(id[a], id[b]);
				}
			} else {

				scanf ("%d", &a);
				int p = getParent (id[a]);
				printf ("%d %d\n", cnt[p], sum[p]);
			}
		}
	}
	return 0;
}
