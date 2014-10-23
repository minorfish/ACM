#include <cstdio>
#include <cstring>

typedef long long ll;

const int N = 1005;
ll A[N];

int main () {

	int T;
	int n;
	scanf ("%d", &T);
	while (T--) {

		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			scanf ("%I64d", &A[i]);

		int ans = 0;
		bool flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (A[i] == 1 && flag)
				ans ^= 1;
			else
				flag = 0;
		}
		printf ("%s\n", ans? "No":"Yes");	
	}
	return 0;
}
