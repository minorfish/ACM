#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 10005;

int p[N];
int n;
int vis[N];

int Max (const int a, const int b) {return a > b? a: b;}

void print(int count) {
	
	for (int i = 0; i < count; i++) {

		for (int j = i; j < n; j += count) {

			printf ("%d", p[j]);
			if (j + count < n)
				printf (" ");
			else
				printf ("\n");
		}
	}
}

int main () {

	int t = 0;
	int count;
	while (scanf ("%d", &n), n) {

		if (t)
			printf ("\n");
		t++;

		memset (vis, 0, sizeof(vis));
		count = 0;

		for (int i = 0; i < n; i++) {
			
			scanf ("%d", &p[i]);
			count = Max (count, ++vis[p[i]]);
		}

		sort (p, p + n);
		printf ("%d\n", count);
		print(count);
	}
	return 0;
}
