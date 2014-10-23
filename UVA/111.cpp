#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 25;
const int maxn = 10005;

int n;
int f[N];
int temp[N];
char str[maxn];

void translate (int * num) {
	
	memcpy (temp, num, n * sizeof (int));
	for (int i = 0; i < n; i++) 
		num[temp[i] - 1] = i;		
}

void handle (int * num) {

	int cnt = 0;
	int ans = 0;
	for (int i = 0; i <= strlen (str); i++) {

		if (str[i] >= '0' && str[i] <= '9') {

			ans = ans * 10 + str[i] - '0';		
		} else {

			num[cnt++] = ans;
			ans = 0;
		}
	}

	translate (num);
}


int main () {

	int num[N];
	int vis[N];
	int num1[N];
	bool flag = 0;

	scanf ("%d%*c", &n);			
	while (gets(str) != NULL) {

		if (!flag) {
			
			handle(num);
			flag = 1;
			for (int i = 0; i < n; i++)
				vis[num[i]] = i;
		} else {

			handle(num1);
			for (int i = 0; i < n; i++) {
				num1[i] = vis[num1[i]];
				f[i] = 1;
			}
	
			for (int i = 0; i < n; i++)
				for (int j = i - 1; j >= 0; j--) {
					
					if (num1[i] > num1[j])
						if (f[j] + 1 > f[i])
							f[i] = f[j] + 1;
				}

			int ans = 0;
			for (int i = 0; i < n; i++)
				if (ans < f[i])
					ans = f[i];
			printf ("%d\n", ans);
		}	
	}
	return 0;
}
