#include <cstdio>
#include <cstring>
#include <cmath>

const int N = 20;
const int maxn = 1 << N;
const double esp = 10005;

int member[N][2];
double dist[maxn];
double d[N][N];
char name[N + 5];
int n;

double Min (const double a, const double b) { return a < b ? a: b; }

double distance (int i, int j) { 

	double x = member[i][0] - member[j][0];
	double y = member[i][1] - member[j][1];
	return sqrt (x * x + y * y);
}

double dfs (int s) {

	int news; 
	double& ans = dist[s];

	if (ans != esp)
		return ans;
	if (s == (1 << (2 * n)) - 1)
		return 0; 
	for (int i = 0; i < 2 * n; i++)
		for (int j = i + 1; j < 2 * n; j++) {

			if ((s & (1 << i)) || (s & (1 << j)))
				continue;
			news = (s | (1 << i)) | (1 << j);
//			printf ("%d\n", news);
			ans = Min (ans, dfs (news) + d[i][j]);			
		}
	return ans;
}

void init () {

	for (int i = 0; i < 1 << (2 * n); i++)
		dist[i] = esp;
//	printf ("%lf\n", dist[0]);
	for (int i = 0; i < 2 * n; i++)
		for (int j = i + 1; j < 2 * n; j++) {

			d[i][j] = d[j][i] = distance(i, j);
//			printf ("%lf\n", d[i][j]);
		}
}

int main () {

	int cas = 0;
	while (scanf ("%d", &n), n) {

		for (int i = 0; i < 2 * n; i++)
			scanf ("%s%d%d", name, &member[i][0], &member[i][1]);

		init();
		printf ("Case %d: %.2lf\n", ++cas, dfs(0));
	}
	return 0;
}
