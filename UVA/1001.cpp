#include <cstdio>
#include <cstring>

const int maxn = 1005;
int notprime[maxn];

void init () {

	for (int i = 2; i < maxn; i++) {
		if (notprime[i]) 
			continue;
		for (int j = 2 * i; j < maxn; j += i)
			notprime[j] = 1;	
	}
}

int main () {

	int N, num, sum;

	init ();
	while (scanf ("%d", &N) != EOF) {
	
		sum = 0;
		for (int i = 0; i < N; i++) {
			scanf ("%d", &num);
			if (!notprime[num])
				sum += num;
		}
		
		printf ("%d\n", sum);
	}
	return 0;
}
