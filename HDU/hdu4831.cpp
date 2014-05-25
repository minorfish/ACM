#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int N = 100005;
const int inf = 1e8 + 1;

struct SP {

	int d, v;
	int flag;
	int w1, w2;
} sp[N];
int n, m, mv;

void back_track () {

	mv = -1;
	for (int j = n - 1; j >= 0; j--) {

		if (sp[j].flag == 0)
			sp[j].w2 = mv;
		else
			mv = j;
	}
}

bool find (int x, int j) {

	int d1, d2;
	d1 = d2 = inf;
	if (sp[j].w1 != -1)
		d1 = abs (sp[sp[j].w1].d - sp[j].d);
	if (sp[j].w2 != -1)
		d2 = abs (sp[sp[j].w2].d - sp[j].d);

	if (d1 < d2 && sp[sp[j].w1].v <= x)
		return true;
	if (d1 > d2 && sp[sp[j].w2].v <= x)
		return true;
	if (d1 == d2) {
		int Max = (sp[sp[j].w1].v > sp[sp[j].w2].v) ? sp[sp[j].w1].v:sp[sp[j].w2].v;
		if (Max <= x)
			return true;	

	}
	return false;
}

void init () {

	scanf("%d", &n);
	for (int j = 0; j < n; j++)
		sp[j].flag = 0;
	mv = -1;
}

int main () {

	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; i++) {

		init();
		for (int j = 0; j < n; j++) {

			scanf ("%d%d", &sp[j].d, &sp[j].v);
			if (sp[j].v) {

				sp[j].flag = 1;
				mv = j;
			} else 	
				sp[j].w1 = mv;
		}

		back_track();
		//op_init
		scanf("%d", &m);
		printf("Case #%d:\n", i);
		char str[5];
		int count, x, y;
		//op
		while (m--) {

			scanf("%s", str);

			if (str[0] == 'Q') {

				count = 0;
				scanf("%d", &x);
				for (int j = 0; j < n; j++) {

					if (sp[j].flag && sp[j].v <= x)
						count++;
					if (sp[j].flag == 0 && find (x, j))
						count++;
				}
				printf("%d\n", count);
			} else {

				scanf("%d%d", &x, &y);
				sp[x].v = y;
			}
		}
	}
	return 0;
}
