#include <cstdio>
#include <cstring>

const int N = 20;

int v1[N], v2[N];
int l1 ,l2;
int type1[N], type2[N];//用来记录各种牌的最大值
char c1[N];//自己的牌
char c2[N];//对方的牌


int translate (char ch) {

	if (ch >= '3' && ch <= '9')
		return ch - '0';
	switch (ch) {

		case 'T' : return 10;
		case 'J' : return 11;
		case 'Q' : return 12;
		case 'K' : return 13;
		case 'A' : return 14;
		case '2' : return 15;
		case 'X' : return 16;
		case 'Y' : return 17;
	}
}

void cut (char *c, int * v) {//分解

	int n;
	for (int i = 0; i < strlen(c); i++) {

		n = translate(c[i]);
		v[n]++;
	}

}

int Max (int k, int num) {//找num个相同牌的最大值

	if (k == 0) {
		for (int i = 17; i >= 3; i--)
			if (v1[i] >= num) //注意是大于等于
				return i;	

	} else {
		for (int i = 17; i >= 3; i--) 
			if (v2[i] >= num) 
				return i;
	}
	return 0;
}

int Max_1 (int k, int num, int tail) {//找3带1或是3带2的情况

	if (k == 0) {
		for (int i = 17; i >= 3; i--)
			if (v1[i] >= num) {
				for (int j = 17; j >= 3; j--)
					if (j != i && v1[j] >= tail)
						return i;
			}

	} else {
		for (int i = 17; i >= 3; i--)
			if (v2[i] == num) {
				for (int j = 17; j >= 3; j--)
					if (j != i && v2[j] >= tail)
						return i;
			}
	}
	return 0;
}

bool is_empty () {  //判断能否走完

	if (l1 == 6 && type1[0])
		return true;
	if (l1 == 5 && type1[3])
		return true;
	if (l1 == 4 && (type1[0] || type1[2]))
		return true;
	if (l1 == 3 && type1[1])
		return true;
	if (l1 == 2 && type1[4])
		return true;
	if (l1 == 1)
		return true;
	return false;
}

bool solve () {

	memset (type1, -1, sizeof (type1));
	memset (type2, -1, sizeof (type2));
	l1 = strlen (c1);
	l2 = strlen (c2);

	//双飞
	if (v1[16] && v1[17])
		return true;
	//炸弹
	type1[0] = Max (0, 4);		
	type2[0] = Max (1, 4);
	if (type1[0] > type2[0] && !(v2[16] && v2[17]))
		return true;
	//3带0
	type1[1] = Max (0, 3);
	type2[1] = Max (1, 3); 	
	if (type1[1] > type2[1] && !(v2[16] && v2[17]) && !type2[0])
		return true;
	//3带1
	type1[2] = Max_1 (0, 3, 1);
	type2[2] = Max_1 (1, 3, 1);
	if (type1[2] > type2[2] && !(v2[16] && v2[17]) && !type2[0])
		return true;
	//3带2
	type1[3] = Max_1 (0, 3, 2);
	type2[3] = Max_1 (1, 3, 2);
	if (type1[3] > type2[3] && !(v2[16] && v2[17]) && !type2[0])
		return true;
	//对子
	type1[4] = Max (0, 2);
	type2[4] = Max (1, 2);
	if (type1[4] > type2[4] && !(v2[16] && v2[17]) && !type2[0])
		return true;
	//单枝
	type1[5] = Max (0, 1);
	type2[5] = Max (1, 1);
	if (type1[5] > type2[5] && !(v2[16] && v2[17]) && !type2[0])
		return true;
	//能否走完
	if (is_empty())
		return true;
	return false;

}

int main () {

	int t;
	scanf ("%d", &t);
	while (t--) {

		scanf ("%s%s", c1, c2);

		memset (v1, 0, sizeof (v1));
		memset (v2, 0, sizeof (v2));
		cut (c1, v1);
		cut (c2, v2);

		printf ("%s\n", solve()? "Yes": "No");
	}
	return 0;
}
