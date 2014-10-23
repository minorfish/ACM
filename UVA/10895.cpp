#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 10005;
struct Mat {

	int th, val;
};

vector<Mat> v[N];
vector<Mat> ans;
vector<int> th, val;
int cnt[N];
int m, n;

void solve () {

	printf ("%d %d\n", n, m);

	memset (cnt, 0, sizeof (cnt));	
	Mat tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[j].size() && cnt[j] < v[j].size() && v[j][cnt[j]].th == i) {
				tmp.th = j;
				tmp.val = v[j][cnt[j]].val;
				ans.push_back(tmp);
				cnt[j]++;
			}
		}

		printf ("%d", ans.size());
		for (int j = 0; j < ans.size(); j++)
			printf (" %d", ans[j].th + 1);
		printf ("\n");

		if (ans.size()) {
			for (int j = 0; j < ans.size(); j++) {
				if (j != ans.size() - 1)
					printf ("%d ", ans[j].val);
				else
					printf ("%d\n", ans[j].val);
			}
		} else
			printf ("\n");
		ans.clear();
	}

	for (int i = 0; i < m; i++)
		v[i].clear();
}

int main () {

	int num, a;
	Mat tmp;
	while (scanf ("%d%d", &m, &n) != EOF) {

		for (int i = 0; i < m; i++) {

			scanf ("%d", &num);
			th.clear();
			val.clear();

			for (int j = 0; j < num; j++) {
				scanf ("%d", &a);
				th.push_back(a);
			}

			for (int j = 0; j < num; j++) {
				scanf ("%d", &a);
				val.push_back(a);
			}

			for (int j = 0; j < num; j++) {
				tmp.th = th[j] - 1;
				tmp.val = val[j];
				v[i].push_back(tmp);
			}	
		}
		solve();
	}
	return 0;
}
