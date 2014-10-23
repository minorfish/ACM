#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

const int N = 1e5 + 5;
const int M = 20;

int left[N], right[N];
int A[N];

struct Num {

	int value, count;
	Num (const int value = 0, const int count = 0): value(value) , count(count) {}
};

vector<Num> v;
map<int, int> num;

int d[N][M];
int n;

void RMQ_init () {

	int l = v.size();
	for (int i = 0; i < l; i++) 
		d[i][0] = v[i].count;
	for (int j = 1; (1<<j) <= l; j++) 
		for (int i = 0; i + (1<<j) - 1 < l; i++) 	
			d[i][j] = max (d[i][j - 1], d[i + (1<<(j - 1))][j - 1]);	
}

int RMQ (int l, int r) {

	int k = 0;
	while ((1<<(1 + k)) <= (r - l + 1)) k++;
	return max (d[l][k], d[r - (1<<k) + 1][k]);	
}

int main () {

	int q;
	while (scanf ("%d", &n) && n) {

		scanf ("%d", &q);

		v.clear();
		num.clear();

		for (int i = 0; i < n; i++) {
			scanf ("%d", &A[i]);
			if (v.size() && v[v.size() - 1].value == A[i])
				v[v.size() - 1].count++;
			else {
	
				num[A[i]] = v.size();
				v.push_back(Num(A[i], 1));
				left[num[A[i]]] = i;
			}	
		}

		for (int i = 0; i < v.size(); i++) 
			right[num[v[i].value]] = left[num[v[i].value]] + v[i].count - 1;

		RMQ_init();

		int l, r;
		int ans;
		while (q--) {

			scanf ("%d%d", &l, &r);
			l--;
			r--;
			if (A[l] != A[r]) {
				ans = max (right[num[A[l]]] - l + 1, r - left[num[A[r]]] + 1);
				if (num[A[l]] + 1 <= num[A[r]] - 1) 
					ans = max (ans, RMQ(num[A[l]] + 1, num[A[r]] - 1));	
			} else
				ans = r - l + 1;
			printf ("%d\n", ans);
		}	
	}
	return 0;
}
