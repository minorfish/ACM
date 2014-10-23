#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 15;
const double pi = acos(-1.0);

struct Rec {

	double v[3][3];
	Rec () { memset (v, 0, sizeof (v));}
	void init (double Cx, double Cy, double r) {

		v[0][0] = cos(r);
		v[0][1] = sin(r);
		v[1][0] = -sin(r);
		v[1][1] = cos(r);
		v[2][0] = Cx - Cx * cos(r) + Cy * sin(r);
		v[2][1] = Cy - Cx * sin(r) - Cy * cos(r); 
		v[2][2] = 1;	
	}

	Rec operator * (const Rec& a) {
	
		Rec tmp;	
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++) 
					tmp.v[i][j] += v[i][k] * a.v[k][j];		
		return tmp;	
	}

	Rec operator *= (const Rec& a) {
		return *this = *this * a; 
	}

}rec[N];

int main () {

	int T;
	int n;
	double x, y, r;
	scanf ("%d", &T);
	while (T--) {
		
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			
			scanf ("%lf%lf%lf", &x, &y, &r);
			rec[i].init (x, y, r);
		}

		Rec ans = rec[0];
		for (int i = 1; i < n; i++)
			ans *= rec[i];
		
		r = atan2 (ans.v[0][1], ans.v[0][0]);
		if (r < 0)
			r = 2 * pi + r;
		double a1 = (1 - ans.v[0][0]);
		double a2 = ans.v[0][1];
		double b1 = a1;
		double b2 = a2;
		double A = ans.v[2][0];
		double B = ans.v[2][1];
		y = (A * b2 + B * a1) / (a1 * b1 + a2 * b2);
		x = (b1 * y - B) / b2;
		printf ("%.10lf %.10lf %.10lf\n", x, y, r);
	}
	return 0;
}
