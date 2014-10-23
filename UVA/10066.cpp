#include <cstdio>
#include <cstring>

const int N = 105;
typedef long long ll;

int s1[N], s2[N];
int l[N][N];
ll h[N][N];
int l1, l2;

void init () {

	memset (l, 0, sizeof (l));
	memset (h, 0, sizeof (h));
}

ll Max (const ll a, const ll b) { return a > b? a: b; }

int main () {

	int cas = 0;
	while (scanf ("%d%d", &l1, &l2), l1 || l2) {

		for (int i = 1; i <= l1; i++)
			scanf ("%d", &s1[i]);
		for (int i = 1; i <= l2; i++)
			scanf ("%d", &s2[i]);

		init ();

		for (int i = 1; i <= l1; i++) 
			for (int j = 1; j <= l2; j++) {
		
				if (s1[i] == s2[j]) {

					h[i][j] = h[i - 1][j - 1] + s1[i];
		//			printf ("%lld\n", h[i][j]);
					l[i][j] = l[i - 1][j - 1] + 1;
				} else {
				
					h[i][j] = Max (h[i - 1][j], h[i][j - 1]);
					if (h[i - 1][j] > h[i][j - 1])
						l[i][j] = l[i - 1][j];
					else if (h[i - 1][j] < h[i][j - 1])
						l[i][j] = l[i][j - 1];
					else
						l[i][j] = Max (l[i][j - 1], l[i - 1][j]);
				}
		}

/*		for (int i = 1; i < l1; i++) {
			for (int j = 1; j < l2; j++)
				printf ("%lld ", h[i][j]);
			printf("\n");
		}*/

		printf ("Twin Towers #%d\n", ++cas);
		printf ("Number of Tiles : %d\n\n", l[l1][l2]);
	}
	return 0;
}
