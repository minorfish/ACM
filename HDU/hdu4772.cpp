#include <stdio.h>
#include <string.h>

const int N = 35;

int p1[N][N], p2[N][N];
int n;

int Max (const int x, const int y ) { return x > y ? x: y;}
int cmp (int k) {

	int count = 0;
	if (k == 0) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) 	
				if (p1[i][j] == p2[i][j])
					count++;
	} else if (k == 1) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (p1[i][j] == p2[j][n - 1 - i])
					count++;
	} else if (k == 2) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (p1[i][j] == p2[n - 1 - i][n - 1 - j])
					count++;
	} else {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (p1[i][j] == p2[n - 1 - j][i])
					count++;
	}
	return count;
}

int main () {

	int max;
	while (scanf ("%d", &n), n) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf ("%d", &p1[i][j]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf ("%d", &p2[i][j]);

		max = -1;
		for (int i = 0; i < 4; i++) 	
			max = Max (max, cmp(i));

		printf ("%d\n", max);

	}
	return 0;
}
