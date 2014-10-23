#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;
const int maxn = 10010;

int rec[N][N];
int f[maxn], num[maxn], s[maxn], y[maxn], d[maxn], p[maxn];
int n, m;

void init (int& cnt) {

	cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (rec[i][j] || (i == n && j == m)) {
				
				s[cnt] = (i - 1) * m + j;
				y[cnt] = j;
				d[cnt++] = rec[i][j];
			}
		}
}

void printf_ans (int cnt) {

	if (cnt == -1)
		return;
	printf_ans(p[cnt]);
	if (d[cnt])
		printf (" %d", s[cnt]);
}

int main () {

	int a, b, cnt, cas = 0;
	while (scanf ("%d%d", &n, &m) && n != -1 && m != -1) {

		memset (rec, 0, sizeof (rec));
		while (scanf ("%d%d", &a, &b) , a && b) {

			rec[a][b] = 1;
		}

		init (cnt);

		for (int i = 0; i < cnt; i++) {
			f[i] = 0;
			num[i] = 1;
			p[i] = -1;
		}

		for (int i = 0; i < cnt; i++)  {
			for (int j = i - 1; j >= 0; j--) {

				if (y[j] <= y[i]) {
					
					if (f[j] > f[i]) {
						f[i] = f[j];
						p[i] = j;
						num[i] = num[j];
					} else if (f[j] == f[i]) {

						num[i] += num[j];
						p[i] = j;
					}
				}
			}

			f[i] += d[i];
		}

		printf ("CASE#%d: %d %d", ++cas, f[cnt - 1], num[cnt - 1]);
		printf_ans(cnt - 1);
		printf ("\n");
	}
	return 0;
}
