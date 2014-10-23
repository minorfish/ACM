#include <stdio.h>
#include <string.h>

const int N = 80;
const int INF = 0x3f3f3f3f;

int mat[N][N], tem[N][N];
int n;

int Max (const int x , const int y) {return x > y ? x: y;}

int c_max () {

	int mm = -INF;
	int sum;
	for (int k = 0; k < n; k++) {

		sum = tem[0][k];
		mm = Max (mm, sum);
		if (sum < 0)
			sum = 0;
		for (int j = 1; j < n; j++) {

			sum += tem[j][k];
			if (sum < 0)
				sum = 0;
			else
				mm = Max (mm, sum);					
		}
	}
	return mm;
}

int c_max1 () {

	int mm = -INF;
	int sum;
	for (int k = 0; k < n; k++) {

		sum = tem[k][0];
		mm = Max (mm, sum);
		if (sum < 0)
			sum = 0;
		for (int j = 1; j < n; j++) {

			sum += tem[k][j];
			if (sum < 0)
				sum = 0;
			else
				mm = Max (mm, sum);					
		}
	}
	return mm;
}

int solve () {

	int mm = -INF;
	memset (tem, 0, sizeof (tem));
	for (int i = 0; i < n; i++) {

		for (int k = 0; k < n; k++) {

			for (int j = i; ; j = (j + 1) % n) {

				if (i != j)
					tem[k][j] = tem[k][(j - 1 + n) % n] + mat[k][j];
				else
					tem[k][j] = mat[k][j];

				if ((j + 1) % n == i)
					break;
			}
		}
		mm = Max(mm, c_max()); 	
		memset (tem, 0, sizeof (tem));
	}
		
	for (int i = 0; i < n; i++) {

		for (int k = 0; k < n; k++) {

			for (int j = i; ; j = (j + 1) % n) {

				if ( j != i)
					tem[j][k] = tem[(j - 1 + n) % n][k] + mat[j][k];
				else
					tem[j][k] = mat[j][k];	
				if ((j + 1) % n  == i)
					break;
			}
		}
		mm = Max (mm, c_max1());
		memset (tem, 0, sizeof (tem));
	}
	return mm;
}

int main () {

	int t;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf ("%d", &mat[i][j]);

		printf ("%d\n", solve());
	}
	return 0;
}
