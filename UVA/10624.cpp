#include <cstdio>
#include <cstring>

const int N = 35;
typedef unsigned long long ll;

int num[N];
int m, n;

bool judge (int cur) {

	ll sum = 0;
	for (int i = 0; i <= cur; i++) {
		sum = sum * 10 + num[i];
		if (i > 17)
			sum = sum % (cur + 1);
	}
	sum = sum % (cur + 1);
	return sum ? false : true;
}

bool dfs (int cur) {

	if (cur == m) 
		return true;
	for (int i = 0; i < 10; i++) {
		
		if (!cur && !i)
			continue;

		num[cur] = i;
		if (cur < n - 1 || judge(cur)) {
			if (dfs (cur + 1))
				return true;
		}
	}
	return false;
}

int main () {

	int t;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {

		scanf ("%d%d", &n, &m);
		printf ("Case %d: ", i);
		if (!dfs(0)) 
			printf ("-1\n");
		else {
			for (int j = 0; j < m; j++)
				printf ("%d", num[j]);
			printf ("\n");
		}
	}
	return 0;
}
