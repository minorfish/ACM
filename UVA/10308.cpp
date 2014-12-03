#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 10005;
int vis[maxn];
int ans;

struct node {
	int id, val;
	node (int id = 0, int val = 0) {
		this->id = id;
		this->val = val;
	}
};
vector<node> v[maxn];

int dfs (int r) {

	int num = 0;
	int n = v[r].size();
	vis[r] = 1;
	for (int i = 0; i < n; i++)
		if (!vis[v[r][i].id]) {
			int tmp = dfs(v[r][i].id) + v[r][i].val;
			ans = max (ans, tmp + num);
			num = max (num, tmp);
		}
	vis[r] = 0;
	return num;
}

int main () {

	char str[1000];
	int a, b, val;
	while (true) {
	
		ans = 0;
		for (int i = 1; i <= maxn - 5; i++)
			v[i].clear();

		while (gets(str) != NULL && str[0] != '\0') {
			sscanf (str, "%d%d%d", &a, &b, &val);
			v[a].push_back(node(b, val));
			v[b].push_back(node(a, val));
		}

		dfs(1);	
		printf ("%d\n", ans);

		if (str[0] != '\0')
			break;
	}
	return 0;
}
