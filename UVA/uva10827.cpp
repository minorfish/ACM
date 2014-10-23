#include <stdio.h>
#include <string.h>

const int N = 200;
const int INF = 0x3f3f3f3f;
int mat[N][N], temx[N], temy[N];
int n;

int Max (const int x, const int y) {return x > y? x: y;}

int main () {

	int t;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {

				scanf ("%d", &mat[i][j]);
				mat[i][j + n] = mat[i + n][j] = mat[i + n][j + n] = mat[i][j];
			}
		
		int mm = -INF;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				memset (temx, 0, sizeof (temx));
				for (int x = i; x < i + n; x++) {	
					for (int y = j; y < j + n; y++) {
						
							if (y == j)
								temy[y] = mat[x][y];
							else
								temy[y] = temy[y - 1] + mat[x][y];
							temx[y] += temy[y];	
							mm = Max (mm, temy[y]);
							mm = Max (mm, temx[y]);
					}
			}
		}
	}
	printf ("%d\n", mm);
	}
	return 0;
}

