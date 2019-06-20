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

#define MAX (1 << 12)

int X[16];
int Y[16];
int B[16];
int Z[16];
int D[16][16];
int A[16][MAX][2];
int gMode;
int gPos;
int gCnt;
int n;

Int gcd(Int a, Int b){ return a == 0 ? b : gcd(b % a, a); }

void F(int pos, int cnt, int sum)
{
	if(pos < n)
		A[pos][sum][gMode] += Z[cnt];

	int i;
	if(cnt != 0)
		FOR(i, 0, n)
			if(B[i] == 0)
			{
				B[i] = 1;
				F(i, cnt - 1, sum + D[pos][i]);
				B[i] = 0;
			}
}

void Out(Int a, Int z)
{
	Int g = gcd(a, z);
	printf("%lld/%lld\n", a/g, z/g);
}

int SolveTest()
{
	scanf("%d", &n);

	int i, j, k;
	FOR(i, 0, n + 2)
		scanf("%d%d", &X[i], &Y[i]);

	reverse(X, X + n + 2);
	reverse(Y, Y + n + 2);

	FOR(i, 0, n + 2)
		FOR(j, 0, n + 2)
			D[i][j] = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);

	Z[0] = 1;
	FOR(i, 0, n)
		Z[i + 1] = Z[i]*(i + 1);

	CLEAR(A, 0);
	CLEAR(B, 0);
	gMode = 0;
	F(n + 1, n, 0);
	gMode = 1;
	F(n, n, 0);

	Int res[] = {0, 0};
	FOR(i, 0, n)
	{
		Int total[] = {Z[n], Z[n]};
		FOR(j, 0, MAX)
		{
			Int a[] = {A[i][j][0], A[i][j][1]};

			res[0] += a[0]*(total[1] - a[1]);
			res[1] += a[1]*(total[0] - a[0]);

			total[0] -= a[0];
			total[1] -= a[1];
		}
	}

	Int z = Int(n)*Int(Z[n])*Int(Z[n]);
	Out(res[0], z);
	Out(res[1], z);
	Out(z - res[0] - res[1], z);
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


