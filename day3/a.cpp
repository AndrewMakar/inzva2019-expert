#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = a; i < b; i++)
#define RFOR(i, a, b) for(i = a - 1; i >= b; i--)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size()) 
#define ALL(a) (a).begin(),(a).end() 

#define PB push_back
#define MP make_pair

#define MAX 10

int X[MAX];
int Y[MAX];

int Cross(int x, int y, int xx, int yy){ return x*yy - xx*y; }

double Dist(double x, double y){ return sqrt(x*x + y*y); }

double F(double x, double y)
{
	double res = 0;
	int i;
	FOR(i, 0, MAX)
		res = max(res, Dist(X[i] - x, Y[i] - y));

	return res;
}

int SolveTest()
{
	int i, j, k;
	FOR(i, 0, MAX)
		scanf("%d%d", &X[i], &Y[i]);

	double res = 1e4;
	FOR(i, 0, MAX)
		res = min(res, F(X[i], Y[i]));

	FOR(i, 0, MAX)
		FOR(j, 0, i)
			res = min(res, F((X[i] + X[j] + 0.0)/2, (Y[i] + Y[j] + 0.0)/2));

	FOR(i, 0, MAX)
		FOR(j, 0, i)
			FOR(k, 0, j)
			{
				int dx = X[j] - X[i];
				int dy = Y[j] - Y[i];
				int dxx = X[k] - X[i];
				int dyy = Y[k] - Y[i];
				if(Cross(dx, dy, dxx, dyy) == 0)
					continue;

				int a1 = dy + dy;
				int b1 = -dyy - dyy;
				int c1 = X[k] - X[j];
				int a2 = -dx - dx;
				int b2 = dxx + dxx;
				int c2 = Y[k] - Y[j];

				int d = Cross(a1, b1, a2, b2);
				int dd = Cross(c1, b1, c2, b2);

				double x = (X[i] + X[j] + 0.0)/2 + ((dd + 0.0)/d)*dy;
				double y = (Y[i] + Y[j] + 0.0)/2 - ((dd + 0.0)/d)*dx;
				res = min(res, F(x, y));
			}

	printf("%.4lf\n", res);
	return 0;
}


int main()
{
	SolveTest();
	return 0;
};


