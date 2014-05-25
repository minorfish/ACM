#include <stdio.h>
#include <string.h>

const int N = 10;

char str[N * N], s1[3][N];
int s[N * N];
char vis[N * N], head[N * N];
const char *letter = "IVXLCDM";
int	count, size;

void init () {

	s['I'] = 1;
	s['X'] = 10;
	s['C'] = 100;
	s['M'] = 1000;
	s['V'] = 5;
	s['L'] = 50;
	s['D'] = 500;
	size = 0;
}

int trans (char * a) {

	int num = 0, i;
	for (i = 1; i <= strlen (a); i++) {

		if (s[a[i - 1]] >= s[a[i]])
			num += s[a[i- 1]];
		else
			num -= s[a[i - 1]];
	}
	return num;
}

bool is_roman () {

	int n1 = trans(s1[0]);
	int n2 = trans(s1[1]);
	int n3 = trans(s1[2]);
	if (n1 + n2 == n3)
		return true;
	return false;
}

int tran_num (char * a) {

	int num = 0;
	for (int i = 0; i < strlen (a); i++)
		num = num * 10 + s[a[i]];
	return num;
}

void is_numerals (int n, int v) {

	if (n == size) {

		int n1 = tran_num (s1[0]);
		int n2 = tran_num (s1[1]);
		int n3 = tran_num (s1[2]);
		if (n1 + n2 == n3) 	
			count++;
		return ;
	}
	if (v >= 7)
		return;
	while(!vis[letter[v]]) 
		v++;
	if (v < 7) {
		for (int j = 0; j < 10; j++) {

			if (j == 0 && head[letter[v]])
				continue;
			s[letter[v]] = j;
			is_numerals (n + 1, v + 1);
			if (count >= 2)
				return;
		}
	} 
}

int main () {

	int k, j;
	while (scanf ("%s", str) , str[0] != '#') {

		init();
		k = j = 0;
		memset (vis, 0, sizeof (vis));
		memset (head, 0, sizeof (head));
		for (int i = 0; i < strlen (str); i++) {

			if (str[i] != '+' && str[i] != '=' ) {

				s1[k][j++] = str[i];
				if (!vis[str[i]])
					size++;
				vis[str[i]] = 1;
				if (j == 1)
					head[str[i]] = 1;
			} else {

				s1[k][j] = '\0';
				k++;
				j = 0;
			}
		}
		s1[2][j] = '\0';
		printf ("%s ", is_roman() ?"Correct":"Incorrect");

		count = 0;
		is_numerals(0, 0);

		if (!count)
			printf ("impossible\n");
		else {

			if (count == 1)
				printf ("valid\n");
			else
				printf ("ambiguous\n");
		}
	}
	return 0;
}
