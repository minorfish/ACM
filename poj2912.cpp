#include <stdio.h>
#include <string.h>

const int N = 505;
const int M = 2005;
int n, m, f[N], c[N];
int r[M][2], vis[M];

void init () {

	for (int i = 0; i < n; i++) {

		f[i] = i;
		c[i] = 0;
	}
}

int getfather (int x) {

	if ( x != f[x] ) {

		int t = f[x];
		f[x] = getfather(f[x]);
		c[x] =  (c[x] + c[t] ) % 3;
	}
	return f[x];
}

int main () {

	char ch;
	int x, y;
	int flc, count, max, judge;
	while (scanf ("%d%d", &n, &m) != EOF) {

		//		init ();
		count = 0;
		max = 0;
		memset (vis, 0, sizeof (vis));
		for (int i = 0; i < m; i++) {

			scanf ("%d", &x);
			while (scanf ("%c", &ch) , ch == ' ');
			scanf ("%d", &y);
			if (ch == '<') {

				r[i][0] = x;
				r[i][1] = y;
			} else  if (ch == '>') {

				r[i][0] = y;
				r[i][1] = x;
			} else {

				r[i][0] = x;
				r[i][1] = y;
				vis[i] = 1;
			}
		}
		for (int i = 0; i < n; i++) {

			init ();	
			flc = 0;
			for (int j = 0; j < m; j++) {

				if (r[j][0] == i || r[j][1] == i) 	
					continue;
				int p = getfather (r[j][0]);
				int q = getfather (r[j][1]);
				int d = (vis[j] + 1) % 2;
				if (p != q) {

					f[q] = p;
					c[q] = (c[r[j][0]] - c[r[j][1]] + 3 + d) % 3;

				} else  {

					if ( (c[r[j][0]] + d) % 3 !=  c[r[j][1]]) {

						flc = j + 1;
						if (max < flc)
							max = flc;
						break;

					}
				}
			}
			if (!flc)
				count++;
			if ( !flc && count == 1) {
				judge = i;
				//				printf ("%d\n", i);
			}
		}
		if (!count)
			printf ("Impossible\n");
		else if (count > 1)
			printf ("Can not determine\n");
		else
			printf ("Player %d can be determined to be the judge after %d lines\n", judge, max);
	}
	return 0;
}
