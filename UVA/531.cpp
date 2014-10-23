#include <cstdio>
#include <cstring>

const int N = 105;
const int M = 35;

char w1[N][M]; 
char w2[N][M];

int f[N][N];
int p[N][N][2];
int ans[N];
int n1, n2;

void printf_ans (int x, int y) {

	if (x == 0 || y == 0)
		return;
	printf_ans (p[x][y][0], p[x][y][1]);
	if (strcmp (w1[x - 1], w2[y - 1]) == 0)
		ans[f[x][y]] = x - 1;	
}

int main () {

	n1 = n2 = 0;
	while (scanf ("%s", w1[n1++]) != EOF) {
		
		while (scanf ("%s", w1[n1]) && w1[n1][0] != '#') {
			n1++;
		}
		while (scanf ("%s", w2[n2]) && w2[n2][0] != '#') {
			n2++;
		}

		for (int i = 0; i <= n1; i++)
			f[i][0] = 0;
		for (int i = 0; i <= n2; i++)
			f[0][i] = 0;
		
		for (int i = 1; i <= n1; i++)
			for (int j = 1; j <= n2; j++) {

				if (strcmp(w1[i - 1], w2[j - 1]) == 0)  {

					f[i][j] = f[i - 1][j - 1] + 1;
					p[i][j][0]  = i - 1;
					p[i][j][1]  = j - 1;
				} else { 

					if (f[i][j - 1] > f[i - 1][j]) {
						f[i][j] = f[i][j -1];
						p[i][j][0] = i;
						p[i][j][1] = j - 1;
					} else {

						f[i][j] = f[i - 1][j];
						p[i][j][0] = i - 1;
						p[i][j][1] = j;
					}
				}
			}

		printf_ans(n1, n2);		
		for (int i = 1; i < f[n1][n2]; i++)
			printf ("%s ", w1[ans[i]]);
		printf ("%s\n", w1[ans[f[n1][n2]]]);
		n1 = n2 = 0;
	}

}
