#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

const int maxn = 10000;

int main () {

	srand(time(0));
	int T = rand()%(maxn - 1) + 1;
	
	while (T--) {
		
		int n = rand()%maxn;
		int m = rand()%maxn;
		printf ("%d %d\n", n + m, 2 * n + 4 * m);
	}
	return 0;
}
