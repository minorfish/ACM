#include <stdio.h>
#include <string.h>

const int N = 30;
int f1[N], f2[N], e, map[N][N], path[N], count, city[N];

void init () {

	for (int i = 0; i < N; i++) {

		f1[i] = i;
		f2[i] = i;
	}
}

int getfather1 (int x) {

	return (f1[x] == x) ? x : f1[x] = getfather1 (f1[x]);
}

int getfather2 (int x) {

	return (f2[x] == x) ? x : f2[x] = getfather2 (f2[x]);
}

void dfs (int s, int n) {

	if (s == e) {

		count++;
		for (int i = 0; i < n; i++)
			if (i != n - 1)
				printf ("%d ", path[i]);
			else
				printf ("%d\n", path[i]);
		return;
	}
	for (int i  = 0; i < N; i++) 
		if (map[s][i] && f1[i] == 1 && f2[i] == e && !city[i]) {

			city[i] = 1;
			path[n] = i;
			dfs (i, n + 1);
			city[i] = 0;
		}
			
}

int main () {

	int x, y;
	int cas = 0;
	while (scanf ("%d", &e) == 1) {
		
		init();
		memset(map, 0, sizeof(map));
		memset(city, 0, sizeof(city));
		while (scanf ("%d%d",  &x, &y) , y || x) {
			
			map[x][y] = map[y][x] = 1;
			int p = getfather1 (x);
			int q = getfather1 (y);
			int r = getfather2 (x);
			int v = getfather2 (y);
			if (p != q)  {

				if (q == 1)	
				f1[p] = q;
				else if (p == 1)
					f1[q] = p;
				else 
					f1[p] = q;
				if (r == e)
					f2[v] = r;
				else if (v == e)
					f2[r] = v;
				else
					f2[r] = v;
			}
		}
		for (int i = 1; i < N; i++) 
			if (f1[i] != 1)
				getfather1(i);
		for (int i = 1; i < N; i++)
			if (f2[i] != e)
				getfather2 (i);
		printf ("CASE %d:\n", ++cas);
		count = 0;
		path[0] = 1;
		city[1] = 1;
		dfs (1, 1);
		printf ("There are %d routes from the firestation to streetcorner %d.\n", count, e);
	}
	return 0; 
}
