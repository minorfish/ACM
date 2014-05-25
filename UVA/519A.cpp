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

int rec[M][M], vis[N], list[M + 2][N];
char str[M];
int n, m, cnt[M + 2], p_value[N];
bool flag;

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

void clasify (int i, int k) {

	if (str[i] == 'F')
		list[i * 3][cnt[i * 3]++] = k;
	else if (str[i] == 'I')
		list[i * 3 + 1][cnt[i * 3 + 1]++] = k;
	else
		list[i * 3 + 2][cnt[i * 3 + 2]++] = k;
}

void handle (int k) {

	for (int i = 0; i < strlen (str); i++) {

		if (i == 0) 
			puzzle[k].top = interpret(str[i]);
		else if (i == 1) 
			puzzle[k].right = interpret(str[i]);	
		else if (i == 2) 
			puzzle[k].bottom = interpret(str[i]);	
		else
			puzzle[k].left = interpret(str[i]);

		clasify (i, k); 
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
	if (x == 1)
		k = 0;
	else if (x == n)
		k = 6;
	else if (y == 1)
		k = 9;
	else if (y == m)
		k = 3;
	else  {

		if (puzzle[rec[x - 1][y]].bottom == 0) 
			k = 0;	
		else if (puzzle[rec[x - 1][y]].bottom == 1)
			k = 1;
		else if (puzzle[rec[x - 1][y]].bottom == 2)
			k = 2;
		else if (puzzle[rec[x][y - 1]].right == 0)
			k = 9;
		else if (puzzle[rec[x][y - 1]].right == 1)
			k = 10;
		else if (puzzle[rec[x][y - 1]].right == 2)
			k = 11;
	}
	for (int i = 0; i < cnt[k]; i++) {

		if (map[p_value[list[k][i]]])
			continue;
		if (vis[list[k][i]])
			continue;
		if (!((puzzle[list[k][i]].left + puzzle[rec[x][y - 1]].right) % 3) && !((puzzle[list[k][i]].top + puzzle[rec[x - 1][y]].bottom) % 3)) {

			rec[x][y] = list[k][i];
			vis[list[k][i]] = 1;
			if (y + 1 > m) 
				dfs (x + 1, 1);
			else
				dfs (x, y + 1);
			if (flag)
				return;
			vis[list[k][i]] = 0;
			map[p_value[list[k][i]]] = 1;
		}
	}
}

void init () {

	flag = 0;
	memset (cnt, 0, sizeof (cnt));
	memset (rec, 0, sizeof (rec));
	memset (vis, 0, sizeof (vis));
	memset (list, 0, sizeof (list));
	puzzle[0].top = puzzle[0].left = puzzle[0].bottom = puzzle[0].right = 0;

}

int main () {

	while (scanf ("%d%d", &n, &m) , n || m) {

		init ();	
		for (int i = 1 ; i <= n * m; i++) {

			scanf ("%s", str);
			handle(i);
		}

		int n1 = 0, n2 = 0;
		for (int i = 0; i < 4; i++) {

			n1 += cnt[i * 3 + 1];
			n2 += cnt[i * 3 + 2];
		}

		if (cnt[0] == m && n1 == n2 && cnt[3] == n && cnt[6] == m && cnt[9] == n) { 

			for (int i = 1; i <= n * m; i++)  
				p_value[i] = hash(i);
			dfs (1, 1);
		}

		printf ("%s\n", flag == 1?"YES":"NO");
	}
	return 0;
}
