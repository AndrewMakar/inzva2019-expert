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
typedef long double Double;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<string,string> PSS;
typedef vector<int> VInt;
typedef vector<double> VDouble;
typedef vector<string> VString;
typedef vector<char> VChar;
typedef vector<Int> VLong;

#define FOR(i, a, b) for(i = a; i < b; i++)
#define RFOR(i, a, b) for(i = a - 1; i >= b; i--)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOREACH(i, a) for(i = (a).begin(); i != (a).end(); i++)
#define RFOREACH(i, a) for(i = (a).rbegin(); i != (a).rend(); i++)
#define PB push_back
#define MP make_pair

#define min(a, b) ((a < b) ? (a) : (b))
#define max(a, b) ((a > b) ? (a) : (b))
/************************************************************/
char buf[1 << 20];
int Res[2][1 << 21];
int I[32];

int F(int a, int b, int c)
{
	int& res = Res[c][ I[a] + b ];
	if(res != -1)
		return res;

	if(a == 0)
		return res = ((buf[b] - '0' == c) ? 0 : 1);

	return res = min(F(a - 1, b << 1, c) + F(a - 1, (b << 1) + 1, c), F(a - 1, b << 1, c^1) + F(a - 1, (b << 1) + 1, c^1) + 1);
}

int SolveTest()
{
	int N;
	scanf("%d%s", &N, buf);

	int i, j;
	I[0] = 0;
	FOR(i, 1, 20)
		I[i] = I[i - 1] + (N >> (i - 1));

	CLEAR(Res, -1);
	int res = N;
	FOR(i, 0, 2)
	{
		int r = 0;
		FOR(j, 0, 20)
			if(N & (1 << j))
				r += F(j, (N >> j) - 1, i);

		res = min(res, r);
	}

	printf("%d\n", res);
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};

