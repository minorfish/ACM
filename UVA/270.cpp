#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <set>
using namespace std;

const int N = 705;
const double esp = 1e-9;

int n;
char str[N];
double ki[N];
int visit[N];

multiset <double> K;

struct NODE {

	double x, y;
}node[N];

double Max (const double a, const double b) { return a > b ? a: b; }
double Fabs (const double a, const double b) { 

	if (a > b)
		return a - b;
	return b - a;
}
/*
void change (int k) {

	node[k].x = 0;
	node[k].y = 0;
	int i;
	for (i = 0; i < strlen (str) && str[i] != ' '; i++)
		node[k].x = node[k].x * 10 + str[i] - '0';
	for (int j = i + 1; j < strlen (str); j++)
		node[k].y = node[k].y * 10 + str[j] - '0';
//	printf ("%lf %lf\n", node[k].x, node[k].y);
}
*/
int main () {
		
	int t;
	int cnt;
	int count;
	scanf ("%d%*c%*c", &t);
	while (t--) {
		
		n = 0;		
		while (gets(str) != NULL && str[0] != '\0') {
		
			sscanf (str, "%lf%lf", &node[n].x, &node[n].y);
			n++;
		}
		
		cnt = 0;
		for (int i = 0; i < n; i++) {
			K.clear();
			count = 0;
			memset (visit, 0, sizeof (visit));
			for (int j = 0; j < n; j++) {

				if (i == j)
					continue;
				if (Fabs (node[i].x, node[j].x) <= esp) {
					
					count++;
					continue;
				}
				else 
		            ki[j] = (node[i].y - node[j].y) / (node[i].x - node[j].x); 	
				K.insert (ki[j]);
				visit[j] = 1;
            //   printf ("%d %d %lf\n", i, j, ki[j]);
			}

			for (int j = 0; j < n; j++) {
					
				 if (visit[j]) {

					 cnt = Max (cnt, K.count(ki[j]));
//					 printf ("%d\n", K.count(ki[j]));
				 }
			}
			cnt = Max (cnt, count);
		}
		
		printf ("%d\n", cnt + 1);
		if (t)
		printf ("\n");
			
	}
	return 0;
}
