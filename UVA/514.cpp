#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

const int N = 1005;
int tail[N], n;

stack<int> s;

bool ok () {

	while (!s.empty()) {
		s.pop();
	}
	
	int k = 1;
	int p = 0;
	while (k <= n && p < n) {

		if (k == tail[p]) {
			p++;
			k++;
		} else if (!s.empty() && s.top() == tail[p]) {
			s.pop();
			p++;
		} else {
			s.push (k);
			k++;
		}
	}

	while (!s.empty() && p < n) {

		if (s.top() == tail[p]) {
			s.pop();
			p++;
		} else
			break;
	}

	if (p == n)
		return true;
	return false;

}

int main () {

	bool flag;
	while (scanf ("%d", &n) && n) {

		flag = 1;
		while (1) {

			for (int i = 0; i < n; i++) {
				scanf ("%d", &tail[i]);
				if (!tail[i]) {
					flag = 0;
					break;
				}
			}

			if (!flag)
				break;
			
			printf ("%s\n", ok() ? "Yes": "No");	
		}
		printf ("\n");
	}
	return 0;
}
