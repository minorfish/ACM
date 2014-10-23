#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

const int N = 1005;

int n;
int op[N][2];

queue<int> q;
stack<int> s;
priority_queue<int> p;

bool is_queue () {

	while (!q.empty()) {
		q.pop();
	}

	for (int i = 0; i < n; i++) {

		if (op[i][0] == 1)
			q.push(op[i][1]);

		else {
			
			if (!q.empty() && q.front() == op[i][1])
				q.pop();
			else
				return false;
		}
	}
	return true;
}

bool is_priority_queue () {

	while (!p.empty()) {
		p.pop();
	}
	
	for (int i = 0; i < n; i++) {

		if (op[i][0] == 1)
			p.push(op[i][1]);
		else {
			
			if (!p.empty() && p.top() == op[i][1])
				p.pop();
			else
				return false;
		}
	}
	return true;
}

bool is_stack () {

	while (!s.empty()) {
		s.pop();
	}

	for (int i = 0; i < n; i++) {
	
		if (op[i][0] == 1)
			s.push(op[i][1]);
		else {

			if (!s.empty() && s.top() == op[i][1])
				s.pop();
			else
				return false;
		}
	}
	return true;
}

int main () {

	while (scanf ("%d", &n) != EOF) {

		for (int i = 0; i < n; i++)
			scanf ("%d%d", &op[i][0], &op[i][1]);			
		
		bool f1 = is_stack();
		bool f2 = is_queue();
		bool f3 = is_priority_queue();

		if (f1 && !f2 && !f3)
			printf ("stack\n");
		else if (!f1 && f2 && !f3)
			printf ("queue\n");
		else if (!f1 && !f2 && f3)
			printf ("priority queue\n");
		else if (!(f1 | f2 | f3))
			printf ("impossible\n");
		else
			printf ("not sure\n");
	}
	return 0;
}
