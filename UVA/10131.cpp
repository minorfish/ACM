#include <cstdio>
#include <cstring>

const int N = 1005;

int elephants[N][2];
int d[N][N];
int G[N][N];
int n;

void init () {

	memset (d, -1, sizeof (d));
}

void handle () {

	memset (G, 0, sizeof (G));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {

			if (i == j)
				continue;
			if (elephants[i][0] < elephants[j][0] && elephants[i][1] > elephants[j][1])
				G[i][j] = 1;
		}
}

int Max (const int a, const int b) { return a > b? a: b; }

int DP (int x, int y) {

	int& ans = d[x][y];
	if (ans != -1)
		return ans;
	for (int i = 0; i < n; i++) {

		if (i == y)
			continue;
		if (G[y][i])
			ans = Max (ans, DP(y, i) + 1);
	}

	if (ans == -1)
		ans = 2;
	return ans;
}

void printf_ans (int x, int y) {

	printf ("%d\n", x + 1);
	if (d[x][y] == 2) {
		
		printf ("%d\n", y + 1);
		return;
	}

	for (int i = 0; i < n; i++) {

		if (i == y)
			continue;
		if (G[y][i] && d[x][y] == d[y][i] + 1) {
			printf_ans (y, i);
			break;
		}
	}
}

int main () {

	n = 0;
	while (scanf ("%d%d", &elephants[n][0], &elephants[n][1]) != EOF) {

		n++;
	}

	handle();
	init ();

	int ans, temp;
	ans = -1;
	int x, y;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {

			if (G[i][j]) {	
				temp = DP(i, j);
				if (temp > ans) {

					x = i;
					y = j;
				}
				ans = Max (ans, temp);	
			}
		}
		
	if (ans != -1) {

		printf ("%d\n", ans);	
		printf_ans (x, y);		
	} else 
		printf ("1\n1\n");
	return 0;
}
