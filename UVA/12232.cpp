#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2e4 + 5;
const int maxn = 4e4 + 5;

int n, Q;
int p[N];
int v[N];

struct Query {

	char type;
	int a, b, val;
	int k, l[100];
} q[maxn];

void init () {

	for (int i = 0; i <= n; i++) {
		p[i] = i;
		v[i] = 0;
	}
}

int getParent (const int a) {

	if (a == p[a])
		return a;
	int t = p[a];
	p[a] = getParent (p[a]);
	v[a] ^= v[t];
	return p[a];
}

void solve () {

	int cnt = 0;
	for (int i = 1; i <= Q; i++) {

		if (q[i].type == 'I') {

			cnt++;
			int p1 = getParent (q[i].a);
			int p2 = getParent (q[i].b);
			if (p1 == p2) {
				
				if ((v[p1] ^ v[q[i].a] ^ v[q[i].b]) != q[i].val) {
					printf ("The first %d facts are conflicting.\n", cnt);
					return;
				}
			} else {

				if (p1 == n)
					swap (p1, p2);
				p[p1] = p2;
				v[p1] = (v[q[i].a] ^ v[q[i].b] ^ q[i].val);
			}
		} else {

			int ans = 0;
			int parent[N];
			bool flag = 1;
			memset (parent, 0, sizeof (parent));
			for (int j = 0; j < q[i].k; j++) {

				getParent (q[i].l[j]);
				ans ^= v[q[i].l[j]];
				if (p[q[i].l[j]] != n)
					parent[p[q[i].l[j]]] ^= 1;
			}
				
			for (int j = 0; j <= n; j++) {

				if (parent[j]) {
					flag = 0;
					break;
				}
			}

			if (flag)
				printf ("%d\n", ans);
			else
				printf ("I don't know.\n");
		}
	}
}

int main () {

	char str[105];
	int a, b, val;
	int cas = 0;
	while (scanf ("%d%d", &n, &Q) && (n || Q)) {

		init ();
		printf ("Case %d:\n", ++cas); 
		for (int i = 1; i <= Q; i++) {
			scanf ("%s", str);
			q[i].type = str[0];
			if (q[i].type == 'I') {
					
				gets(str);
				if (sscanf (str, "%d%d%d", &q[i].a, &q[i].b, &q[i].val) == 2) {
					q[i].val = q[i].b;
					q[i].b = n;
				}
			} else {

				scanf ("%d", &q[i].k);
				for (int j = 0; j < q[i].k; j++)
					scanf ("%d", &q[i].l[j]);
			}
		}
		
		solve();
		printf ("\n");
	}
	return 0;
}
