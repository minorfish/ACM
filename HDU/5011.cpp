#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;
int num[N];

int main () {

	int n;
	while (scanf ("%d", &n) != EOF) {

		for (int i = 0; i < n; i++)
			scanf ("%d", &num[i]);
		sort (num, num + n);
		
		int t1, t2;
		t1 = t2 = 0;
		int i;
		for (i = 0; i < n; i++) {
			
			if (num[i] == 2)
				break;
			t1++;
		}

		for (int j = i; j < n; j++) {

			if (num[j] != 2)
				break;
			t2++;
		}

		if (t1 == n)
			printf ("%s\n", t1 % 2 ? "Win": "Lose");
		else {
			
			t1 = n - (t1 + t2);
			int flag = (t1 % 2) ^ (t2 % 2);
			printf ("%s\n", flag ? "win": "Lose");	
		}
	}
	return 0;
}
