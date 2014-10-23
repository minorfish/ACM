#include <cstdio>
#include <cstring>

const int maxn = 10005;
int dp1[maxn];
int dp2[maxn];
int v[maxn];
int LIS[maxn];
int p;

int Max (const int a, const int b) { return a > b? a: b; }

int bsearch (int s) {

	int l = 0;
	int r = p;
	int mid;
	while (l < r) {

		mid = l + (r - l) / 2;	
		if (s > LIS[mid])
			l = mid + 1;
		else if (s < LIS[mid])
			r = mid;
		else
			return mid;
	}
	return l;
}

int main () {

	int n;
	int k;
	while (scanf ("%d", &n) != EOF) {

		for (int i = 0; i < n; i++)
			scanf ("%d", &v[i]);

		p = 0;
		LIS[p] = v[0];
		dp1[0] = 1;
		dp2[n - 1] = 1;
		for (int i = 1; i < n; i++) {

			if (v[i] > LIS[p]) {
				LIS[++p] = v[i]; 
				dp1[i] = p + 1;
			} else if (v[i] < LIS[p]) {

				k = bsearch (v[i]);
				dp1[i] = k + 1;
				LIS[k] = v[i];
			} else
				dp1[i] = p + 1;
		}

		p = 0;
		LIS[p] = v[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			
			if (v[i] > LIS[p]) {

				LIS[++p] = v[i];
				dp2[i] = p + 1;
			} else if (v[i] < LIS[p]) {

				k = bsearch (v[i]);
				dp2[i] = k + 1;
				LIS[k] = v[i];
			} else 
				dp2[i] = p + 1;
		}

		int ans = 1;
		for (int i = 0; i < n; i++) {
			
			if (dp1[i] <= dp2[i])
				ans = Max (ans, 2 * dp1[i]);
			else
				ans = Max (ans, 2 * dp2[i]);
		}

/*		for (int i = 0; i <= p; i++)
			printf ("%d ", LIDS[i]);
		printf ("\n");*/
		printf ("%d\n", ans - 1);	
	}
	return 0;
}

