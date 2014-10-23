#include <cstdio>
#include <map>
#include <vector>

using namespace std;

map<int , vector<int> > vis;

int main () {

	int n, m;
	int v, k;
	while (scanf ("%d%d", &n, &m) != EOF) {
	
		vis.clear();
		for (int i = 1; i <= n; i++) {

			scanf ("%d", &v);
			if (!vis.count(v))
				vis[v] = vector<int> ();
			vis[v].push_back(i);
		}
		
		for (int i = 0; i < m; i++) {
			scanf ("%d%d", &k, &v);
			if (!vis.count(v) || vis[v].size() < k) 
				printf ("0\n");
			else
				printf ("%d\n", vis[v][k - 1]);
		}
	}
	return 0;
}
