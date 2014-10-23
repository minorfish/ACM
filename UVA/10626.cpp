#include <cstdio>
#include <cstring>

const int N1 = 705;
const int N2 = 155;
const int N3 = 55;
const int INF = 0x3f3f3f3f;

int f[N1][N2][N3];

void init () {

	for (int i = 0; i < N1; i++)
		for (int k = 0; k < N2; k++)
			for (int l = 0; l < N3; l++)
				f[i][k][l] = INF;
}

int Min (const int a, const int b) { return a < b? a: b;}

int DP (int c, int n1, int n2, int n3) {

//	printf ("%d %d %d %d\n", c, n1, n2, n3);
	int& ans = f[n1][n2][n3];
	if (ans != INF)
		return ans;
	if (c == 0) 
		return ans = 0;

	if (!n2 && !n3) 
		return ans = 8 * c;

	if (n3) 	
		ans = Min (ans, DP(c - 1, n1 + 2, n2, n3 - 1) + 1);
	if (n2 >= 2) 
		ans = Min (ans, DP(c - 1, n1 + 2, n2 - 2, n3) + 2);
	if (n2 && n1 >= 3)
		ans = Min (ans, DP(c - 1, n1 - 3, n2 - 1, n3) + 4);
	if (n3 && n1 >= 3)
		ans = Min (ans, DP(c - 1, n1 - 3, n2 + 1, n3 - 1) + 4);
	return ans;
}

int main () {

	int t;
	int c, n1, n2, n3;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%d%d%d%d", &c, &n1, &n2, &n3); 
		init ();
		printf ("%d\n", DP(c, n1, n2, n3));
	}
	return 0;
}
