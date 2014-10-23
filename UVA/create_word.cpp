#include <cstdio>
#include <string>
#include <cstdlib>
#include <ctime>

int main () {

	int T;
	srand(time(0));
	while (1) {
		T = rand() % 1000;
		if (T)
			break;
	}

	printf ("%d\n", T);
	while (T--) {

		int n = rand() % 1000;

		while (n--) {

			int len = rand() % 100;
			for (int i = 0; i < len; i++) {

				int seed = rand()%26;
				printf ("%c", 'A' + seed);
			}
			if (n)
				printf (" ");
			else
				printf ("\n");
		}
		printf ("\n");
	}

}
