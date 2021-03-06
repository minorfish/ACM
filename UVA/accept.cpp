#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 5;

char str[maxn];
int n;

int main () {

	int T;
	char ch;
	scanf ("%d", &T);
	getchar();

	for (int i = 1; i <= T; i++) {
		int ans = 0;
		while ((ch = getchar()) != EOF && ch != '\n') {

			if (ch == 'G')
				ans++;
			while ((ch = getchar()) != EOF) {

				if (ch == ' ' || ch == '\n')
					break;
			}

			if (ch == '\n')
				break;
		}
		printf ("Case %d: %d\n", i, ans);
	}
	return 0;
}

