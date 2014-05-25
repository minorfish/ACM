#include <stdio.h>


int main () {
	
	int t, x;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {

		printf ("Case #%d:\n", i);
		scanf ("%d", &x);
		x = 10 - x / 10;
		printf ("*------------*\n");
		for (int j = 0; j < 10; j++)
			if (j < x)
				printf ("|............|\n");
			else
				printf ("|------------|\n");
		printf ("*------------*\n");
	}
	return 0;
}
