#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int N = 4e4 + 5;
typedef long long ll;

map<int , int> A, B;
map<int , int>::iterator it;

int main () {
	
	int n, m;
	int num;
	while (scanf ("%d%d", &n, &m) != EOF) {
	
		A.clear();
		B.clear();
		int i;
		int sum = 0;
		bool flag = 0;
		for (i = 0; i < n; i++) {
			
			scanf ("%d", &num);
			if (num == m) {
				flag = 1;
			}
			A[i - 2 * sum]++;
			if (num < m)
				sum++;
			if (flag)
				break;
		}
		
		B[i - 2 * sum]++;
		for (int j = i + 1; j < n; j++) {
			
			scanf ("%d", &num);
			if (num < m)
				sum++;
			B[j - 2 * sum]++;
		}
		
		if (!flag)
			printf ("0\n");
		else {

			int ans = 0;
			for (it = A.begin(); it != A.end(); it++) 
				ans += A[it->first] * B[it->first];
			printf ("%d\n", ans);
		}
	}
	return 0;
}
