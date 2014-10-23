#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 5;
int p[maxn];

void init () {
	
	for (int i = 0; i < maxn; i++)
		p[i] = i;
}

int getParent(int a) {

	return a == p[a] ? a: p[a] = getParent (p[a]);
}

int main () {

	int a, b;
	int ans;
	while (scanf ("%d", &a) == 1) {
		ans = 0;
		init();
		do {
			scanf ("%d", &b);
			int q1 = getParent(a);
			int q2 = getParent(b);
			if (q1 == q2)
				ans++;
			else 
				p[q1] = q2;

		} while (scanf ("%d", &a) && a != -1);

		printf ("%d\n", ans);
	}
	return 0;
}
