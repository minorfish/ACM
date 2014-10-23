#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int N = 1005;

vector<int> v[N];
struct Seg {

	int l, r;
	Seg(int l, int r): l(l), r(r) {}
};

queue<Seg> q;

int B[N];
int D[N];
int n;

void solve () {

	q.push(Seg(0, n));
	int p = 1;
	int root;
	while (!q.empty()) {

		Seg s = q.front();
		q.pop();

		if (s.r - s.l <= 1 || p == n)
			continue;

		root = D[s.l];
		int pre = s.l + 1;

		for (int i = pre; i < s.r; i++) {

			if (D[i] == B[p]) {
					
					q.push (Seg (pre, i));
					v[root].push_back (D[i]);	
					p++;
					pre = i;
			}
		}

		if (pre < s.r) 
			q.push (Seg (pre, s.r));
	}
}

int main () {

	int num;
	while (scanf ("%d", &n) == 1) {

		for (int i = 0; i < n; i++) 
			scanf ("%d", &B[i]);

		for (int i = 0; i < n; i++)
			scanf ("%d", &D[i]);
	
		solve();
		for (int i = 1; i <= n; i++) {

			printf ("%d:", i);
			for (int j = 0; j < v[i].size(); j++)
				printf (" %d", v[i][j]);
			printf ("\n");
			v[i].clear();
		}
	}
	return 0;
}
