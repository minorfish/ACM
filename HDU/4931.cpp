#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

const int N = 6;
int A[N];

int main () {

	int T;
	scanf ("%d", &T);
	while (T--) {

		for (int i = 0; i < N; i++)
			scanf ("%d", &A[i]);
		sort (A, A + N, greater<int>());
		if (A[0] + A[1] > A[2] + A[3] + A[4])
			printf ("Grandpa Shawn is the Winner!\n");
		else
			printf ("What a sad story!\n");
	}
	return 0;
}
