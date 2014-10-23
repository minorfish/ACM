#include <cstdio>
#include <cstring>

const int N = 205;
const int INF = 0x3f3f3f3f;

int n;
int gas[N][2];
int f[N][N];
int d[N][N];
char str[N];

int Min (const int a, const int b) { return a < b ? a: b; }

void init () {

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			d[i][j] = gas[j][0] - gas[i][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= 200; j++)
			f[i][j] = INF;
	f[0][100] = 0;
}

int main () {

	int t;
	int D;	
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d%*c", &D);
		n = 1;
		gas[0][0] = 0;
		while (gets(str) != NULL && str[0] != '\0') {

			sscanf (str,"%d%d", &gas[n][0], &gas[n][1]);
			n++;
		}
/*		for (int i = 0; i < n; i++)
			printf ("%d %d\n", gas[i][0], gas[i][1]);*/
		if (gas[n - 1][0] != D) {

			gas[n][0] = D;
			gas[n][1] = 0;
			n++;
		}

		init();
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= 200; j++) {

				for (int l = i - 1; l >= 0; l--) { 
					if (j + d[l][i] <= 200)
						f[i][j] = Min (f[i][j], f[l][j + d[l][i]]);	
					else
						break;
				}
				if (gas[i][1] && f[i][j] != INF) {
					for (int k = j + 1; k <= 200; k++) 
						f[i][k] = f[i][j] + (k - j) * gas[i][1];	
				}
			}
		}

		int ans = INF;
		for (int i = 100; i <= 200; i++) 
			ans = Min (ans, f[n - 1][i]);
		if (ans != INF)
			printf ("%d\n", ans);
		else
			printf ("Impossible\n");
		if (t)
			printf ("\n");
	}
	return 0;
}
