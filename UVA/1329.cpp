#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int p[maxn], cnt[maxn];
int n;

void init () {

	for (int i = 1; i <= n; i++) {
		p[i] = i;
		cnt[i] = 0;
	}
}

int getParent (int a) {

	if (a == p[a])
		return a;
	int b = p[a];
	p[a] = getParent (p[a]);
	cnt[a] += cnt[b];
	return p[a];
}

int main () {

	int T;
	int a, b;
	int q, r;
	char s[10];

	scanf ("%d", &T);
	while (T--) {

		scanf ("%d", &n);
		init ();

		while (scanf ("%s", &s) && s[0] != 'O') {

			if (s[0] == 'E') {

				scanf ("%d", &a);
				q = getParent (a);
				printf ("%d\n", cnt[a]);
			} else {

				scanf ("%d%d", &a, &b);
				p[a] = b;
				cnt[a] += abs (a - b) % 1000;		
			}
		}
	}
	return 0;
}
