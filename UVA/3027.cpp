#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;
int p[maxn], c[maxn];
int n;

void init () {
	
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		c[i] = 0;
	}
}

int getParent (int a) {
	
	if (a == p[a])
		return a;
	int t = p[a];
	p[a] = getParent (p[a]);
	c[a] += c[t];	
	return p[a];
}

int main () {

	int T;
	int a, b;
	char str[10];
	scanf ("%d", &T);
	while (T--) {

		scanf ("%d", &n);
		init();
		while (scanf ("%s", str) != EOF) {
			
			if (str[0] == 'O')
				break;
			if (str[0] == 'E') {

				scanf ("%d", &a);
				int q1 = getParent (a);
				printf ("%d\n", c[a]);
			} else {

				scanf ("%d%d", &a, &b);
				p[a] = b;
				c[a] = abs (a - b) % 1000;
			}
		}
	}
	return 0;
}
