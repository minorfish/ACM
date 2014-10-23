#include <cstdio>
#include <cstring>

const int N = 65;
const int MOD = 10007;

char s1[N];
char s2[N];
char s3[N];

int f1[N][N][N], f2[N][N][N], f[N][N][N];
int l1, l2, l3;

void init () {

	for (int i = 0; i <= l2; i++)
		for (int j = 0; j <= l1; j++) {

			f2[0][j][i] = 1;
			f1[0][j][i] = 1;
			f[0][j][i] = 1;
		}

	for (int i = 1; i <= l3; i++) 
		for (int j = 1; j <= l2; j++) 
			f1[i][0][j] = 0;

	for (int i = 1; i <= l3; i++)
		for (int j = 1; j <= l1; j++)
			f2[i][j][0] = 0; 
}

int main () {

	int t;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%s%s%s", s1, s2, s3);
		l1 = strlen (s1);
		l2 = strlen (s2);
		l3 = strlen (s3);

		init ();

		for (int i = 1; i <= l3; i++)
			for (int j = 0; j <= l1; j++)
				for (int k = 0; k <= l2; k++) {

					if (j) {
						f1[i][j][k] = f1[i][j - 1][k];
						if (s3[i - 1] == s1[j - 1])
							f1[i][j][k] = (f1[i][j][k] + f[i - 1][j - 1][k]) % MOD;
					}
					if (k) {
						f2[i][j][k] = f2[i][j][k - 1];
						if (s3[i - 1] == s2[k - 1])
							f2[i][j][k] = (f2[i][j][k] + f[i - 1][j][k - 1]) % MOD;
					}
					f[i][j][k] = (f1[i][j][k] + f2[i][j][k]) % MOD;
//					printf ("%d %d %d %d %d\n", i, j, k, f1[i][j][k], f2[i][j][k]);
				}
		printf ("%d\n", f[l3][l1][l2]);

	}
	return 0;
}
