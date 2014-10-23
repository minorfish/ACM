#include <stdio.h>

const int N = 10005;
int n;

void solve (int l, int r, int *t, int k) {
	

	if (r + 1 - l <= 2)
		return;
	int m =  l + (r - l) / 2;
	int temp = t[l + 1];
	for (int i = l, j = t[l]; i <= m; i++, j += k)
		t[i] = j;
	for (int i = m + 1, j = temp; i <= r; i++, j += k) 
		t[i] = j;
	solve (l, m, t, k * 2);
	solve (m + 1, r, t, k * 2);

}

int main () {

	while (scanf ("%d", &n), n) {

		int t[N];
		for (int i = 0; i < n; i++)
			t[i] = i;
		solve(0, n - 1, t, 2);
		printf ("%d:", n);
		for (int i = 0; i < n; i++)
			printf (" %d", t[i]);
		printf ("\n");
	}
	return 0;
}
