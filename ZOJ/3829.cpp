#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1005;
char str[maxn];

int main () {

	int T;
	scanf ("%d", &T);
	while (T--) {

		scanf ("%s", str);
		int num, op, ans;
		int len = strlen (str);
		ans = num = op = 0;

		for (int i = 0; i < len; i++)
			if (str[i] == '*')
				op++;
		num = len - op;
		if (!op) {
			printf ("0\n");
			continue;
		}

		if (str[len - 1] != '*') {

			ans++;
			for (int i = 0; i < len; i++)
				if (str[i] == '*') {
					swap(str[i], str[len - 1]);
					break;
				}
		}
		
		int cnt = 0;
		for (int i = 0; i < len; i++) {

			if (str[i] == '*') {

				if (cnt > 1)
					cnt--;
				else {

					if (num >= op + 1) {
						
						for (int j = len - 1; j >= 0; j--)
							if (str[j] != '*') {
								swap(str[j], str[i]);
								cnt++;
								ans++;
								break;
							}

					} else {

						ans++;
						num++;
						if (!cnt) {
							i--;
							cnt = 1;
						}
					}
				}
			} else
				cnt++;
		}

		printf ("%d\n", ans);
	}
	return 0;
}

