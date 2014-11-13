#include <cstdio>
#include <cstring>

int A, B, C;
void solve() {

	int ca, cb;
	ca = cb = 0;
	while (1) {

		if (ca == C || cb == C) {
			printf ("success\n");
			return;
		}
		if (ca == 0) {
			printf ("fill A\n");
			ca = A;
		} else if (cb == B) {
			printf("empty B\n");
			cb = 0;
		} else {

			printf ("pour A B\n");
			if (cb + ca > B) {
				ca = cb + ca - B;
				cb = B;	
			} else {
				cb += ca;
				ca = 0;
			}
		}
	
	}
}

int main () {

	while (scanf ("%d%d%d", &A, &B, &C) != EOF) {

		solve();	
	}
	return 0;
}
