#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 755;
int k;

struct Item {

	int s, b;
	//Item () {}
	Item (int s, int b): s(s), b(b) {}
	bool operator < (const Item &a) const {
		return s > a.s;
	}
};
		
priority_queue<Item> q;

void merge (int *A, int *B, int *C) {

	while (!q.empty()) {
		q.pop();
	}

	for (int i = 0; i < k; i++) 
		q.push (Item (A[i] + B[0], 0));	

	for (int i = 0; i < k; i++) {

		Item item = q.top();
		q.pop();
		C[i] = item.s;
		if (item.b + 1 < k) 
			q.push (Item (item.s - B[item.b] + B[item.b + 1], item.b + 1));	
	}
}

int main () {

	int A[N][N];

	while (scanf ("%d", &k) != EOF) {

		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++)
				scanf ("%d", &A[i][j]);
			sort (A[i], A[i] + k);
		}

		for (int i = 1; i < k; i++)
			merge (A[0], A[i], A[0]);

		for (int i = 0; i < k - 1; i++) 			
			printf ("%d ", A[0][i]);
		printf ("%d\n", A[0][k - 1]);

	}	
	return 0;
}
