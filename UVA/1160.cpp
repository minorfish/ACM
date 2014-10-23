#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 5;

int p[maxn];
int cnt;

void init () {

	cnt = 0;
	for (int i = 0; i < maxn; i++)
		p[i] = i;
}

int getParent (int a) { return a == p[a] ? a: p[a] = getParent(p[a]); }

int main () {

	int a, b;
	int r, q;

	while (scanf ("%d", &a) == 1) {
	
		init ();

		do {	
			scanf ("%d", &b);
			r = getParent (a);
			q = getParent (b);
			if (r == q)
				cnt++;
			else 
				p[r] = q;
		} while (scanf ("%d", &a) && a != -1);

		printf ("%d\n", cnt);
	}
	
	return 0;
}
