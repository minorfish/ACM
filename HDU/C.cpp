#include <cstdio>
#include <cstring>

const int N = 105;

int len;
char str[N];

bool judge (int i) {

	if (str[i] == 'd' && i + 3 < len)
		if (str[i + 1] == 'e' && str[i + 2] == 's' && str[i + 3] == 'u')
			return true;
	return false;
}

int main () {

	int T;
	scanf ("%d", &T);
	for (int cas = 1; cas <= T; cas++) {

		printf ("Case #%d: ", cas);
		scanf ("%s", str);

		bool flag = 0;
		len = strlen (str);

		if (judge (len - 4))
			flag = 1;

		if (flag) {

			for (int i = 0; i < len; i++) {

				if (i == len - 4)
					printf ("nano");
				printf ("%c", str[i]);
			}
			printf ("\n");
		} else 
			printf ("%snanodesu\n", str);
	}
	return 0;
}
