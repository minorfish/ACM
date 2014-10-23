#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int M = 50005;
const int N = 205;

int f[N][M];
int G[N][M];
int color[10];
int n, m, q;
char str[N];

struct OP {

	char type;
	int x, y, l, r, c;
}op[M];

int getParent (int x, int y) { 
	return y == f[x][y] ? y : f[x][y] = getParent (x, f[x][y]);
}

void init() {

	for (int i = q - 1; i >= 0; i--) {

		scanf ("%s", str);
		if (str[0] == 'D')
			scanf ("%d%d%d%d", &op[i].x, &op[i].y, &op[i].l, &op[i].c);
		else if (str[0] == 'T')
			scanf ("%d%d%d%d", &op[i].x, &op[i].y, &op[i].l, &op[i].c);
		else if (str[0] == 'R')
			scanf ("%d%d%d%d%d", &op[i].x, &op[i].y, &op[i].l, &op[i].r, &op[i].c);
		else
			scanf ("%d%d%d%d", &op[i].x, &op[i].y, &op[i].l, &op[i].c);
		op[i].type = str[0];
	}

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			f[i][j] = j;
	memset (color, 0, sizeof (color));
}

void circle (int x, int y, int r, int c) {

	int L, R, s;
	for (int i = -r; i <= r; i++) {

		s = sqrt(r * r - i * i);  
		if (i + x >= n || i + x < 0)
			continue;
		L = max(y - s, 0);
		L = max (getParent (i + x, L), L);
		R = min (s + y, m - 1);
		
		for (int j = L; j <= R; j++) {
			if (j == getParent (i + x, j)) {
				color[c]++;
				f[i + x][j] = R + 1;	
			} else
				j = getParent(i + x, j) - 1;
		}
	}
}

void diamond (int x, int y, int r, int c) {

	int L, R;
	for (int i = -r; i <= r; i++) {

		if (i + x >= n || i + x < 0)
			continue;
		R = min (r - abs(i) + y, m - 1);
		L = max (abs(i) - r + y, 0);
		L = max (L, getParent (i + x, L));

		for (int j = L; j <= R; j++) {
			if (j == getParent (i + x, j)) {
				color[c]++;
				f[i + x][j] = R + 1;
			} else
				j = getParent (i + x, j) - 1;
		}
	}
}

void rectangle (int x, int y, int l, int w, int c) {

	int L, R;
	for (int i = x; i < min(x + l, n); i++) {

		L = max (y, getParent (i, y));
		R = min (y + w - 1, m - 1);

		for (int j = L; j <= R; j++) {
			if (j == getParent (i, j)) {
				color[c]++;
				f[i][j] = R + 1;
			} else
				j = getParent (i, j) - 1;
		}
	}
}

void triangle (int x, int y, int w, int c) {

	int L, R, h;
	h = (w + 1) / 2;
	for (int i = 0; i < h; i++) {

		if (i + x >= n)
			break;
		L = max (y - h + i + 1, 0);
		L = max (getParent(i + x, L), L);
		R = min (y + h - i - 1, m - 1);

		for (int j = L; j <= R; j++) {
		 	if (j == getParent (i + x, j)) {	
				color[c]++;
				f[i + x][j] = R + 1;
			} else
				j = getParent (i + x, j) - 1;
		}
	}
}

void solve () {

	for (int i = 0; i < q; i++) {

		if (op[i].type == 'D')
			diamond (op[i].x, op[i].y, op[i].l, op[i].c);
		else if (op[i].type == 'C')
			circle (op[i].x , op[i].y, op[i].l, op[i].c);
		else if (op[i].type == 'T')
			triangle (op[i].x, op[i].y, op[i].l, op[i].c);
		else
			rectangle (op[i].x, op[i].y, op[i].l, op[i].r, op[i].c);
	}
}

int main () {

	char str[N];
	while (scanf ("%d%d%d", &n, &m, &q) != EOF) {

		init ();

		solve();

		for (int i = 1; i < 9; i++)
			printf ("%d ", color[i]);
		printf ("%d\n", color[9]);
	}
	return 0;
}
