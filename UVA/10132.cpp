#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 300;
const int M = 150;
int n, sum;
char ans[N];
int vis[M];

struct Fragment {

	char str[N];
	int len;
}f[M];

int cmp (const Fragment & a, const Fragment &b) {
	return a.len > b.len;
}

bool judge (int a, int b) {
	
	memset(vis, 0, sizeof(vis));
	vis[a] = vis[b] = 1;
	char temp[N];
	for (int i = 0; i < n; i++) {
		
		if (vis[i])
			continue;
		vis[i] = 1;
		int j;
		for (j = i + 1; j < n; j++) {
			
			if (vis[j])
				continue;
			if (f[i].len + f[j].len == sum) {

				strcpy (temp, f[i].str);
				strcat (temp, f[j].str);
				if (strcmp (temp, ans) == 0) {

					vis[j] = 1;
					break;
				}
				strcpy (temp, f[j].str);
				strcat (temp, f[i].str);
				if (strcmp (temp, ans) == 0) {

					vis[j] = 1;
					break;
				}
			}
		}
		if (j == n)
			return 0;
	}
	return 1;
}

void solve () {
	
	int max = f[0].len;
	int min;
	for (int i = 0; i < n; i++)
		if (f[i].len == sum - max) {
			min = i;
			break;
		}
	for (int i = 0; i < n; i++) {

		if (f[i].len != max)
			return;
		for (int j = min; j < n; j++) {

			if (f[j].len != f[min].len)
				break;
			strcpy (ans, f[i].str);
			strcat (ans, f[j].str);
			if (judge (i, j))
				return;
			strcpy (ans, f[j].str);
			strcat (ans, f[i].str);
			if (judge (i, j))
				return;
		}
	}
}

int main () {

	int t;
	char ch;
	scanf ("%d%*c", &t);
	getchar();
	while (t--) {
		
		n = sum = 0;
		while (gets(f[n].str) != NULL) {
			
			f[n].len = strlen (f[n].str);
			sum += f[n].len;
			if (strcmp(f[n].str,"") == 0)
				break;
			n++;
		}
		sum = sum * 2 / n;
		//printf ("%d %d\n", sum, n);
		sort (f, f + n, cmp);
/*		for (int i = 0; i < n; i++)
			printf ("%s\n", f[i].str);*/
		solve();
		printf ("%s\n", ans);
		if (t)
			printf ("\n");
	}
	return 0;
}
