#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > q;

const int maxn = 25;
const int maxm = (1<<20) + 5;
const int INF = 0x3f3f3f3f;

struct State {
	
	int u;
	int d;
};

vector<State> G[maxm];

char st1[maxn], st2[maxn];
int d[maxm];

int change (int n, char* st) {

	int ans = 0;
	for (int i = 0; i < n; i++) {
		
		ans = (ans<<1);
		if (st[i] == '-')
			ans |= 1; 
	}
	return ans;
}

void add_bug (int num1, int num2, int d) {
	
	 State st;
	 st.u = num2;
	 st.d = d;
	 G[num1].push_back(st);
}

inline void dfs (int n, int k, int t) {
	
	if (k == n) {
		 int num1 = change(n, st1);		
		 int num2 = change(n, st2);
		 add_bug(num1, num2, t); 
		 return;
	}

	char tmp;
	if (st1[k] == '0') {

		st1[k] = '-';
		tmp = st2[k];
		if (st2[k] == '0')
			st2[k] = '-';
		dfs(n, k + 1, t);
		st2[k] = tmp;

		st1[k] = '+';
		tmp = st2[k];
		if (st2[k] == '0')
			st2[k] = '+';
		dfs(n, k + 1, t);
		st2[k] = tmp;

		st1[k] = '0';

	} else {
			
		tmp = st2[k];
		if (st2[k] == '0')
			st2[k] = st1[k];	
		dfs(n, k + 1, t);
		st2[k] = tmp;
	}
}

void read_Graph (int n, int m) {

	int t;
	int T = 1 << n;
	for (int i = 0; i < T; i++)
		G[i].clear();
	for (int i = 0; i < m; i++) {
		
		scanf ("%d%s%s", &t, st1, st2);		
		dfs(n, 0, t);
	}
}

int Dijkstra (int n) {

	int T = 1 << n;
	for (int i = 1; i < T; i++)
		d[i] = INF;
	d[0] = 0;

	q.push(make_pair(d[0], 0));

	pii cur;
	int u, v, w;

	while (!q.empty()) {
	
		cur = q.top();
		q.pop();
	
		u = cur.second;
		if (cur.first != d[u]) continue;
		for (int i = 0; i < G[u].size(); i++) {
			v = G[u][i].u;	
			w = G[u][i].d;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push(make_pair(d[v], v));
			}
		}
	}

	return d[T-1];
}

int main () {

	int n, m, cas = 0;
	printf ("%d\n", INF);
	while (scanf ("%d%d", &n, &m) && (n || m)) {
		
		read_Graph(n, m);
		int ans = Dijkstra(n);

		printf ("Product %d\n", ++cas);
		if (ans == INF)
			printf ("Bugs cannot be fixed.\n\n");
		else
			printf ("Fastest sequence takes %d seconds.\n\n", ans);
	}
	return 0;
}
