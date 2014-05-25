#include <stdio.h>
#include <string.h>

const int N = 35;
const char s[7][7] = {"DONG", "NAN", "XI", "BEI", "ZHONG", "FA", "BAI"};
int tile[N];
char str[N];

int handle () {

	if (str[0] >= '1' && str[0] <= '9') {

		int add;
		switch (str[1]) {

			case 'T': add = 0;break;
			case 'S': add = 9;break;
			case 'W': add = 18;break;
		}
		return add + str[0] - '0';
	} else {

		int i;
		for (i = 0; i < 7; i++)
			if (strcmp(str, s[i]) == 0)
				break;
		return 28 + i;
	}
}

bool dfs (int k, int flag) {

	if (k >= 14) {

		if (flag)
			return true;
		return false;
	}
	for (int i = 1; i < N; i++) {

		if (tile[i] >= 2 && !flag) {

			tile[i] -= 2;
			if (dfs (k + 2, 1)) {

				tile[i] += 2;
				return true;
			} 
			tile[i] += 2;
		}
		if (tile[i] >= 3) {

			tile[i] -= 3;
			if (dfs (k + 3, flag)) {

				tile[i] += 3;
				return true;
			}
			tile[i] += 3;
		}
		if ( (i > 7&& i < 10) || (i > 16 && i < 19) || i > 25)
			continue;
		if (tile[i] >= 1 && tile[i + 1] >= 1 && tile[i + 2] >= 1) {

			tile[i]--;
			tile[i + 1]--;
			tile[i + 2]--;
			if (dfs (k + 3, flag)) {

				tile[i]++;
				tile[i + 1]++;
				tile[i + 2]++;
				return true;
			}
			tile[i]++;
			tile[i + 1]++;
			tile[i + 2]++;
		}
	}
	return false;
}

int main () {

	int ans[N], k, cas = 0;
	while (scanf ("%s", str)) {

		memset (tile, 0, sizeof(tile));
		k = 0;
		if (str[0] == '0')
			break;
		tile[handle()]++;
		for (int i = 0; i < 12; i++) {

			scanf ("%s", str);
			tile[handle()]++;
		}

		for (int i = 1; i < N; i++) {

			if (tile[i] >= 4)
				continue;
			tile[i]++;
			if (dfs (0, 0))
				ans[k++] = i;
			tile[i]--;
		}
	
		printf ("Case %d: ", ++cas);
		if (!k) {

			printf ("Not ready\n");
			continue;
		}
		for (int i = 0; i < k; i++) {

			if (i < k - 1) {

				if (ans[i] >= 1 && ans[i] <= 9)
					printf ("%dT ", ans[i]);
				else if (ans[i] >= 10 && ans[i] <= 18)
					printf ("%dS ", ans[i]- 9);
				else if (ans[i] >= 19 && ans[i] <= 27)
					printf ("%dW ", ans[i] - 18);
				else
					printf ("%s ", s[ans[i] - 28]);
			} else {

				if (ans[i] >= 1 && ans[i] <= 9)              	
					printf ("%dT\n", ans[i]);
				else if (ans[i] >= 10 && ans[i] <= 18)          
					printf ("%dS\n", ans[i] - 9);
				else if (ans[i] >= 19 && ans[i] <= 27)
					printf ("%dW\n", ans[i] - 18);   
				else
					printf ("%s\n", s[ans[i] - 28]);
			}
		}
	}
}
