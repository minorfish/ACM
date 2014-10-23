#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 105;
int n, m, l;
struct MONEY {

	char name[N];
	int money;
	int a, b;
} M[N];
char str[N];

int cmp (const MONEY & x, const MONEY & y) {

	if (x.money < y.money)
		return true;
	else if (x.money > y.money)
		return false;
	else return strcmp (x.name, y.name) < 0 ? true: false;
}

void handle (int j) {
	
	int k = 0;
	for (int i = 0; i < strlen (str); i++) {

		if (str[i] != ':')
			k++;
		else
			break;	
	}
	memcpy (M[j].name, str, sizeof (str));
	M[j].name[k] = '\0';
	
	int sum = 0;
	for (int i = k + 1; i < strlen (str); i++) {

		if (str[i] != ',')
			sum = sum * 10 + str[i] - '0';
		else {
			
			M[j].a = sum;
			sum = 0;
		}
	}
	M[j].b = sum;	
}

void cal (int j) {

	int num = n;
	int sum = 0;
	while (1) {

		if (num / 2 >= m && (num - num / 2 ) * M[j].a >= M[j].b)	{
			
			sum += M[j].b;
			num /= 2;
		} else {
			
			sum += (num - m) * M[j].a;
			M[j].money = sum;
			break;
		}
	}
}

int main () {
	
	int t;
	char ch;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {

		printf ("Case %d\n", i);
		scanf ("%d%d%d%c", &n, &m, &l, &ch);
		for (int j = 0; j < l ; j++) {

			gets(str);
			handle(j);
			cal(j);
		}
		sort (M, M + l, cmp);
		
		for (int j = 0; j < l ; j++)
			printf ("%s %d\n", M[j].name, M[j].money);
	}
	return 0;
}
