#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

const int maxn = 1000;
const int N = 255;

int main () {

	srand(time(0));
	int T = rand() % (maxn - 1) + 1; 

	while (T--) {

		int n = rand() % (N - 1) + 1;  
		for (int i = 0; i < n; i++) {
			
			int m = rand() % 4;
			switch(m) {
			
				case 0 : printf ("("); break;
				case 1 : printf (")"); break;
				case 2 : printf ("["); break;
				case 3 : printf ("]"); break;
			}
		}
		printf ("\n");
	}
	return 0;
}
