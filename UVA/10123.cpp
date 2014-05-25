#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;

const int N = 30;
int l, m, n, ans[N][2], path[3], cnt[3];
int flag;
double wl1, wl2, wr1, wr2;

struct OB {

	int w, l;
} obl[N], obr[N], obm[N];

bool cmp (const OB & x,const  OB &y) {

	if (abs (x.l * x.w) < abs (y.l * y.w))
		return true;
	return false;
}

void solve (int dir, int cur, int bo) {

	if (cur >= n) {

		flag = 1;
		return;
	}
	if (dir == 0) {

		for (int i = path[dir]; i < cnt[dir]; i++) {
//			printf ("%.3lf %.3lf\n", wl1 + ( -3 - obl[i].l) * obl[i].w, wr1);
			if (wl1 + (-3 - obl[i].l) * obl[i].w > wr1) {

				if (bo) {

					flag = -1;
					return;
				}
				path[dir] = i;
				solve( 2 - dir, cur, bo + 1);
				if (flag)
					return;
			} else {

				ans[cur][0] = obl[i].l;
				ans[cur][1] = obl[i].w;
				wl1 += (-3 - obl[i].l) * obl[i].w;
				wl2 += (3 - obl[i].l) * obl[i].w;
				path[dir] = i + 1;
				cur++;
				bo = 0;

			}
		}
		if (path[2 - dir] <=  cnt[2 - dir]) 
			solve (2 - dir, cur, bo);
	} else {

		for (int i = path[dir]; i < cnt[dir]; i++) {

			if (wr2 + (obr[i].l - 3) * obr[i].w > wl2) {

				if (bo) {
					flag = -1;
					return;
				}
				path[dir] = i;
				solve (2 - dir, cur, bo + 1);
				if (flag)
					return;
			} else {

				ans[cur][0] = obr[i].l;
				ans[cur][1] = obr[i].w;
				wr1 += (obr[i].l + 3) * obr[i].w;
				wr2 += (obr[i].l - 3) * obr[i].w;
				path[dir] = i + 1;
				cur++;
				bo = 0;
			}
		}
		if (path[2 - dir] <= cnt[2 - dir])
			solve (2 - dir, cur, bo);
	}
	if (flag)
		return;
}

int main () {

	int p, w, t = 0;
	while (scanf ("%d%d%d", &l, &m, &n), l || m || n) {

		wl1 = wr2 = (l - 3.0) * (l - 3.0) * m / l / 4.0;
		wl2 = wr1 = (l + 3.0) * (l + 3.0) * m / l / 4.0;
//		printf ("wl1 = %.3lfwr1 =  %.3lf\n", wl1, wr1);
		memset (cnt, 0, sizeof (cnt));
		for (int i = 0; i < n; i++) {

			scanf ("%d%d", &p, &w);
			p = p * 2;
			if (p <= 3 && p >= -3){

				obm[cnt[1]].w = w;
				obm[cnt[1]].l = p;
				cnt[1]++;
			} else {

				if (p > 3) {

					obr[cnt[2]].w = w;
					obr[cnt[2]].l = p;
					cnt[2]++;
				} else {

					obl[cnt[0]].w = w;
					obl[cnt[0]].l = p;
					cnt[0]++;
				}
			}
		}
		sort (obl, obl + cnt[0], cmp);
		sort (obr, obr + cnt[2], cmp);
		memset (path, 0, sizeof (path));
		for (int i = 0; i < cnt[1]; i++) {

			wr1 += (obm[i].l + 3) * obm[i].w;
			wl2 += (3 -  obm[i].l) * obm[i].w;
		}
		printf ("Case %d:\n", ++t);
		flag = 0;
		if (wl1 <= wr1 && wr2 <= wl2) {
			
			solve (0, cnt[1], 0);
		}
		if (flag != 1)
			printf ("Impossible\n");
		else {

			for (int i = n - 1; i >= cnt[1]; i--)
				printf ("%d %d\n", ans[i][0]/2, ans[i][1]);
			if (cnt[1] - 1 >= 0)
				for (int i = cnt[1] - 1; i >= 0; i--)
					printf ("%d %d\n", obm[i].l/2, obm[i].w);
		}
	}
	return 0;
}
