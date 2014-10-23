#include <cstdio>
#include <cstring>

typedef long long ll;
const int N = 1e5 + 5;
const int M = 20;

int num[N];
int Map[N];
int n;
ll t[M];

void init () {

	t[0] = 1;
	for (int i = 1; i <= M; i++)
		t[i] = t[i - 1] * 2;
}

int main () {

	init();
	while (scanf ("%d", &n) == 1) {

		for (int i = 0; i <= n; i++)
			scanf ("%d", &num[i]);

		int rear = n;
		int front;
		ll ans = 0;
//		printf ("%lld\n", t[M - 1]);
		while (rear >= 0) {

			for (int i = 0; i < M; i++)
				if (t[i] > rear) {
					front = t[i] - rear - 1;
					break;		
				}

			for (int i = 0; i < (rear - front + 1) / 2; i++) {

				Map[rear - i] = front + i;
				Map[front + i] = rear - i;
			}

			if (rear == front)
				Map[rear] = front;
			rear = front - 1;
		}

		for (int i = 0; i <= n; i++)
			ans += num[i] ^ Map[num[i]];
		printf ("%lld\n", ans);
		for (int i = 0; i < n; i++)
			printf("%d ", Map[num[i]]);
		printf ("%d\n", Map[num[n]]);
	}
	return 0;
}
