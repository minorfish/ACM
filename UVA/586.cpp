#include <cstdio>
#include <cstring>

const int N = 15;
char s1[N], s2[N];
typedef long long ll;
ll nv[N];

void solve (ll * v) {

	while (1) {

		scanf ("%s", s1);
		int num;
		if (s1[0] == 'O') {

			scanf ("%s", s2);
			if (s2[0] != 'n') {
				sscanf (s2, "%d", &num);
				for (int i = 0; i < N; i++)
					if (v[i])
						nv[i] += v[i] * num; 
			} else {

				for (int i = 0; i < N - 1; i++)	
					if (v[i])
						nv[i + 1] += v[i];
			}

		} else if (s1[0] == 'L') {

			scanf ("%s", s2);
			ll tmp[N];
			memset (tmp, 0, sizeof (tmp));
			if (s2[0] != 'n') {

				sscanf (s2, "%d", &num);
				for (int i = 0; i < N; i++)
					tmp[i] = num * v[i];
			} else {

				for (int i = 0; i < N - 1; i++)
					tmp[i + 1] = v[i];
			}	
			solve(tmp);

		} else if (s1[0] == 'E')
			break;
	}	
}

int main () {

	int T, num;
	scanf ("%d", &T);
	for (int cas = 1; cas <= T; cas++) {

		memset (nv, 0, sizeof (nv));
		ll v[N];
		memset (v, 0, sizeof (v));
		v[0] = 1;
		solve(v);
		printf ("Program #%d\n", cas);
		printf ("Runtime = ");
		bool flag = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (nv[j]) {

				if (flag)
					printf ("+");
				if (nv[j] == 1) {
					if (j == 1)
						printf ("n", j);
					else if (j > 1)
						printf ("n^%d", j);
					else
						printf ("%lld", nv[j]);
				} else {

					if (j == 1)
						printf ("%lld*n", nv[j]);
					else if (j > 1)
						printf ("%lld*n^%d", nv[j], j);
					else
						printf ("%lld", nv[j]);
				}
				flag = 1;
			}	
		}
		if (!flag)
			printf ("0");
		printf ("\n\n");
	}
	return 0;
}
