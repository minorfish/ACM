#include <stdio.h>
#include <string.h>

const int N = 100;
const int M = 16;
char str[M * 2];
int t;
int result[M];
bool flag;

struct TOPPING {

	char need[M];
	char omit[M];
	int cnt1, cnt2;
} topping[N];

void init () {

	t = flag = 0;
	memset (topping, 0, sizeof (topping));
}

void handle () {

	for (int i = 0; i < strlen (str); i++) {

		if (str[i] == '+') {

			topping[t].need[topping[t].cnt1++] = str[i + 1];
			i ++;
		} else if (str[i] == '-') {

			topping[t].omit[topping[t].cnt2++] = str[i + 1];
			i ++;
		}
	}
	t++;
}

bool judge() {

	bool tag;
	for (int j = 0; j < t; j++) {	
		tag = 0;
		for (int k = 0; k < topping[j].cnt2; k++) 
			if (result[topping[j].omit[k] - 'A'] == 0) {

				tag = 1;
				break;
			}
		if (tag)
			continue;
		for (int k = 0; k < topping[j].cnt1; k++)
			if (result[topping[j].need[k] - 'A'] == 1) {

				tag = 1;
				break;
			}
		if (!tag)
			return false;
	}
	return true;
}

void solve (int n) {

	int pos = 0;
	while (pos < M) {

		result[pos++] = n & 1;
		n >>= 1;
	}
	if (judge())
		flag = 1;
}

int main () {

	while (scanf ("%s", str) != EOF) {

		init ();
		while (str[0] != '.') {

			handle ();
			scanf ("%s", str);
		}

		int m = 1<<17 - 1;	
		int n = 0;
		//		printf ("%d\n", m);	
		while (n < m) {

			solve (n);
			if (flag)
				break;
			n++;
		}
		if (!flag)
			printf ("No pizza can satisfy these requests.\n");
		else {

			printf ("Toppings: ");
			for (int i = 0; i < M; i++)
				if (result[i])
					printf ("%c", i + 'A');
			printf("\n");

		}
	}
	return 0;
}

