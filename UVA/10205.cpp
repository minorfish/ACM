#include <cstdio>
#include <vector>

using namespace std;

const char Suit[4][10] = {"Clubs", "Diamonds", "Hearts", "Spades"};
const char Value[13][10] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
const int maxn = 105;

int op[maxn][52];
int d[52];

struct card {
	int suit;
	int value;
	card(int suit = 0, int value = 0) {
		this->suit = suit;
		this->value = value;
	}
};

vector<card> v;

void init () {
	
	for (int i = 0; i < 52; i++)
		d[i] = i;	
}

void Operator (int K) {

	int c[52];
	for (int i = 0; i < 52; i++)
		c[i] = d[op[K][i] - 1];

	for (int i = 0; i < 52; i++)
		d[i] = c[i];
}

void output() {
	
	for (int i = 0; i < 52; i++)
		printf ("%s of %s\n", Value[v[d[i]].value], Suit[v[d[i]].suit]);
}

int main () {

	int T, N, K;
	char str[maxn];
	scanf ("%d", &T);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			v.push_back(card(i, j));

	while (T--) {	
		scanf ("%d", &N);
		init();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < 52; j++)
				scanf ("%d", &op[i][j]);
	
		getchar();
		while (gets(str) != NULL && str[0] != '\0') {
				sscanf (str, "%d", &K);
				Operator(K - 1);
		}

		output();
		if (T)
			printf ("\n");
	}
	return 0;
}
