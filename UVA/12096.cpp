#include <cstdio>
#include <cstring>
#include <stack>
#include <set>
#include <map>

using namespace std;

char op[15];
int n;

typedef set<int> E;
stack<E> s;
map<E, int> vis;
E tmp1, tmp2;
set<int>::iterator it;
int num;

void hash (E a) {

	if (!vis.count(a))
		vis[a] = ++num;
}

void Push () {

	tmp1.clear();
	s.push (tmp1);			
}

void Dup () {

	tmp1 = s.top();
	s.push (tmp1);
}

void Add () {

	tmp2 = s.top();
	s.pop();
	tmp1 = s.top();
	s.pop();
	tmp1.insert (vis[tmp2]);
	hash(tmp1);
	s.push(tmp1);
}

void Union () {

	tmp2 = s.top();	
	s.pop();
	tmp1 = s.top();
	s.pop();
	for (it = tmp1.begin(); it != tmp1.end(); it++)
		tmp2.insert (*it);
	hash (tmp2);
	s.push (tmp2);	
}

void Intersect () {

	tmp2 = s.top();
	s.pop();
	tmp1 = s.top();
	s.pop();
	E tmp;
	for (it = tmp1.begin(); it != tmp1.end(); it++)
		if (tmp2.count(*it))
			tmp.insert (*it);
	hash (tmp);
	s.push(tmp);
}

void solve () {

	switch (op[0]) {

		case 'P' : Push();     break;
		case 'D' : Dup();      break;
		case 'U' : Union();    break;
		case 'I' : Intersect(); break;
		case 'A' : Add();      break;
	}
	printf ("%d\n", s.top().size()); 
}

void init () {

	num = 1;
	while (!s.empty()) {
		s.pop();
	}
	vis.clear();
}

int main () {

	int T;
	scanf ("%d", &T);
	while (T--) {
		
		scanf ("%d", &n);
		while (n--) {
			scanf ("%s", op);
			solve();				
		}
		printf ("***\n");
	}
	return 0;
}
