#include <cstdio>
#include <cstring>
#include <queue>
#include <deque>
#include <vector>
#include <map>

using namespace std;

const int N = 7;
queue<int> q;
int ans;

struct State {

	int v[N * 10];
	bool operator < (const State &a) const {
		return memcmp (v, a.v, sizeof(State)) < 0;			
	}
};

queue<int> hand;
deque<int> piles[N];
map<State, int> st;

void handle (deque<int>& pile) {

	while (pile.size() >= 3) {

		int n = pile.size();
		if ((pile[0] + pile[1] + pile[n - 1]) % 10 == 0) {

			hand.push(pile[0]);
			hand.push(pile[1]);
			hand.push(pile[n - 1]);
			pile.pop_front();
			pile.pop_front();
			pile.pop_back();
		} else if ((pile[0] + pile[n - 1] + pile[n - 2]) % 10 == 0) {

			hand.push(pile[0]);
			hand.push(pile[n - 2]);
			hand.push(pile[n - 1]);
			pile.pop_front();
			pile.pop_back();
			pile.pop_back();
		} else if ((pile[n - 1] + pile[n - 2] + pile[n - 3]) % 10 == 0) {

			hand.push(pile[n - 3]);
			hand.push(pile[n - 2]);
			hand.push(pile[n - 1]);
			pile.pop_back();
			pile.pop_back();
			pile.pop_back();
		} else
			return;
	}
}

int solve () {

	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < N; i++) {
			piles[i].push_back(hand.front());
			hand.pop();
		}
	}

	ans = 14;
	State tmp;
	while (hand.size()) {

		for (int i = 0; i < N; i++) {
			if (hand.size() == 52)
				return 1;
			if (piles[i].size() == 0)
				continue;
			if (hand.size()) {
				
				piles[i].push_back(hand.front());
				hand.pop();
				ans++;
				handle(piles[i]);

				int cnt = 0;
				memset (tmp.v, 0, sizeof (tmp.v));
				for (int k = 0; k < N; k++) {
					for (int j = 0; j < piles[k].size(); j++)
						tmp.v[cnt++] = piles[k][j];
					tmp.v[cnt++] = 11;
				}

				queue<int> q = hand;
				while (!q.empty()) {
					tmp.v[cnt++] = q.front();
					q.pop();
				}
				tmp.v[cnt] = 11;

				if (st[tmp])
					return -1;
				else
					st[tmp] = 1;
			} else
				return 0;
		}
	}
	return 0;
}

void init () {

	while (!hand.empty()) {
		hand.pop();
	}
	st.clear();
	for (int i = 0; i < N; i++)
		piles[i].clear();
}

int main () {

	int card;
	while (scanf ("%d", &card) && card) {

		init();
		hand.push(card);
		for (int i = 0; i < 51; i++) {

			scanf ("%d", &card);
			hand.push(card);
		}

		int tmp = solve();
		if (tmp == 0)
			printf ("Loss: %d\n", ans);
		else if (tmp == 1)
			printf ("Win : %d\n", ans);
		else
			printf ("Draw: %d\n", ans);
	}
	return 0;
}
