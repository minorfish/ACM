#include <cstdio>
#include <cstring>

const int N = 10005;

typedef long long ll;

ll t[N];

void init () {

	for (ll i = 1; i <= N - 5; i++)
		t[i] = i * i * i;
}

int main () {

	int T;
	int A, B;

	scanf ("%d", &T);
	init();

	for (int i = 1; i <= T; i++) {

		scanf ("%d%d", &A, &B);

		ll sum = 0;
		for (int j = A; j <= B; j++)
			sum += t[j];

		printf ("Case #%d: %I64d\n", i, sum);
	}
	return 0;
}
