#include <stdio.h>
#include <algorithm>
using namespace std;


const int N = 1005;

struct Shoe {

	int i;
	int t;
	int f;
}s[N];

int cmp (const Shoe &a, const Shoe &b) {return a.t * b.f < b.t * a.f;}

int main () {

	int t;
	scanf ("%d", &t);

	int n;
	while (t--) {

		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {

			scanf ("%d%d", &s[i].t, &s[i].f);
			s[i].i = i + 1;
		}

		sort (s, s + n, cmp);

		for (int i = 0; i < n; i++) {

			if (i == n - 1)
				printf ("%d\n", s[i].i);
			else
				printf ("%d ", s[i].i);
		}
		if (t)
			printf ("\n");
	}
	return 0;
}
