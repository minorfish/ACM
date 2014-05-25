#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;

const int N = 1e6+5;
int f[N];
set<int> vis;

int getfather (int n) {

	return f[n] = (n == f[n]) ? n: getfather(f[n]);
}

void init () {

	for (int i = 0; i < N; i++)
		f[i] = i;
}

int main () {
	
	int x, y, flag, cas = 0, ori;
	while (scanf ("%d%d", &x, &y)) {
		
	  if (x == -1 && y == -1)
		  break;
		
	  init ();
	  flag = 1;
	  ori = x;
	  while (x || y) {

		int p = getfather(x);
		int q = getfather(y);
		vis.insert(x);
		vis.insert(y);
		if (p != q)
			f[q] = p;
		else 
			flag = 0;
		scanf ("%d%d", &x, &y);
	  }

	  ori = getfather(ori);
	  for (set<int>::iterator i = vis.begin(); i != vis.end(); i++)
		 if (getfather(*i) != ori) {

	    	 flag = 0;
	  	   	break;
		 }
	  if (flag)
		  printf ("Case %d is a tree.\n", ++cas);
	  else
		  printf ("Case %d is not a tree.\n", ++cas);
	  vis.clear();
	}
	return 0;
}
