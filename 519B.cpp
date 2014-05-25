#include <stdio.h>
#include <string.h>

const int N = 50;
const int M = 10;

struct PUZZLE {

	int top;
	int left;
	int bottom;
	int right;
} puzzle[N];

int rec[M][M], vis[N];
char str[M];
int n, m, p_value[N];
bool flag;
int c1, c2, c0;

int hash (int k) {

	int num;
	num = puzzle[k].top + puzzle[k].left * 3 + puzzle[k].bottom * 9 + puzzle[k].right * 27; 
	return num;
}

int interpret (char ch) {

	if (ch == 'F')
		return 0;
	if (ch == 'O')
		return 1;
	if (ch == 'I')
		return 2;
}


void handle (int k) {

	for (int i = 0; i < strlen(str); i++) {

		if (i == 0) 
			puzzle[k].top = interpret(str[i]);
		else if (i == 1) 
			puzzle[k].right = interpret(str[i]);	
		else if (i == 2) 
			puzzle[k].bottom = interpret(str[i]);	
		else
			puzzle[k].left = interpret(str[i]);

		if (str[i] == 'F')
			c0++;
		else if (str[i] == 'O')
			c2++;
		else
			c1++;
	}
}

void dfs (int x, int y) {

	if (flag)
		return;
	if (x > n) {

		flag = 1;
		return ;
	}
	int k, map[M * M];
	memset (map , 0, sizeof (map));
	for (int i = 1; i <= n * m; i++) {

		if (x == 1 && puzzle[i].top != 0)
			continue;
		if (x == n && puzzle[i].bottom != 0)
			continue;
		if (y == 1 && puzzle[i].left != 0)
			continue;
		if (y == m && puzzle[i].right != 0)
			continue;
		if (map[p_value[i]])
			continue;
		if (vis[i])
			continue;
		if (!((puzzle[i].left + puzzle[rec[x][y - 1]].right) % 3) && !((puzzle[i].top + puzzle[rec[x - 1][y]].bottom) % 3)) {

			rec[x][y] = i;
			vis[i] = 1;
			if (y + 1 > m) 
				dfs (x + 1, 1);
			else
				dfs (x, y + 1);
			if (flag)
				return;
			vis[i] = 0;
			map[p_value[i]] = 1;
		}
	}
}

void init () {

	flag = 0;
	memset (rec, 0, sizeof (rec));
	memset (vis, 0, sizeof (vis));
	c1 = c2 = c0 = 0;
	puzzle[0].top = puzzle[0].left = puzzle[0].bottom = puzzle[0].right = 0;

}

int main () {

	while (scanf ("%d%d", &n, &m) , n || m) {

		init ();	
		for (int i = 1 ; i <= n * m; i++) {

			scanf ("%s", str);
			handle(i);
		}
		if (c1 == c2 &&  c0 == 2 * (m + n)) { 

			for (int i = 1; i <= n * m; i++)  
				p_value[i] = hash(i);
			dfs (1, 1);
		}

		printf ("%s\n", flag == 1?"YES":"NO");
	}
	return 0;
}
