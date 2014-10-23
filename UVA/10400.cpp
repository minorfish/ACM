#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int N = 105;
const int M = 70000;
const int maxn = 32000;

char op[N];
int num[N];
int n;
int target;
int flag;
char OP[4] = {'*', '-', '+', '/'};
int vis[N][M];

void dfs (int k, int sum) {
	
	if (k == n - 1) {
		
/*	for (int i = 0; i < n - 1; i++)
			printf ("%c ", op[i]);
		printf ("\n");
		printf ("%d\n", sum);*/
		if (sum == target)
			flag = 1;
		return;
	}

	int temp;
	for (int i = 0; i < 4; i++) {
		
		op[k] = OP[i];	
		switch (OP[i]) {

			case '+' : temp = sum + num[k + 1];
					   if (abs (temp) > maxn)
						   break;
					   if (vis[k][temp + maxn])
						   break;
					   dfs (k + 1, temp); break;
			case '-' : temp = sum - num[k + 1];
					   if (abs (temp) > maxn)
						   break;
					   if (vis[k][temp + maxn])
						   break;
					   dfs (k + 1, temp); break;
			case '/' : if (sum % num[k + 1] == 0) {

						   temp = sum / num[k + 1];
						   if (abs (temp) > maxn)
							   break;
					   	if (vis[k][temp + maxn])
						   break;
					   	dfs (k + 1, temp); 
					   }
					   break;
			case '*' : temp = sum * num[k + 1];
					   if (abs (temp) > maxn)
						   break;
					   if (vis[k][temp + maxn])
						   break;
					   dfs (k + 1, temp); break;
		}
		if (flag)
			return;
		else if (abs (temp) <= maxn && !vis[k][temp + maxn])
			 vis[k][temp + maxn] = 1;
	}
}

int main () {

	int t;
	scanf ("%d", &t);
	while (t--) {
	
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			scanf ("%d", &num[i]);
		scanf ("%d", &target);
		flag = 0;
		memset (vis, 0, sizeof (vis));
		dfs(0, num[0]);
//		printf("%d\n", flag);
		if (!flag)
			printf ("NO EXPRESSION\n");
		else {

			for (int i = 0; i < n; i++) {
				
				if (i == n - 1)
					printf ("%d=%d\n", num[i], target);
				else
					printf ("%d%c", num[i], op[i]);
			}
		}
	}
	return 0;
}
