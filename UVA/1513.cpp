#include <cstdio>
#include <cstring>

#define lowbit(x) ((x)&(-x))

const int maxn = 1e5 + 5;

int c[2 * maxn], pos[maxn];
int n, m;

void add (int p, int v) {

	while (p < 2 * maxn) {

		c[p] += v;
		p += lowbit(p);
	}
}

int sum (int p) {

	int ret = 0;
	while (p > 0) {

		ret += c[p];
		p -= lowbit(p);
	}
	return ret;
}

int main () {

	int T;
	scanf ("%d", &T);

	while (T--) {

		memset (c, 0, sizeof (c));
		scanf ("%d%d", &n, &m);
		
		for (int i = 1; i <= n; i++) {

			pos[i] = n - i + 1;
			add(pos[i], 1);
		}
	
		int num;
		int N = n;

		for (int i = 1; i <= m; i++) {

			scanf ("%d", &num);	
			printf ("%d%c", n - sum(pos[num]), i == m ? '\n':' ');	
			add(pos[num], -1);
			pos[num] = ++N;
			add(pos[num], 1);				
		}
	}
	return 0;
}
