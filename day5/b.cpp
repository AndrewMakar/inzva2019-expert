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

#define INF (1 << 30)

int G(int N, int mask, int a)
{
	int i;
	Int res = 0;
	FOR(i, 0, N)
	{
		res *= a;
		res += (mask & (1 << i)) ? 7 : 4;
		if(res > INF)
			return INF;
	}

	return int(res);
}

int F(int N, int mask, int a)
{
	int Min = (mask == 0 ? 5 : 8);
	int Max = (1 << 30);
	while(Max - Min > 1)
	{
		int Mid = (Max + Min) >> 1;
		if(G(N, mask, Mid) > a)
			Max = Mid;
		else
			Min = Mid;
	}

	return G(N, mask, Min) == a ? Min : -1;
}

int SolveTest()
{
	int N;
	scanf("%d", &N);

	if(N == 4 || N == 7)
	{
		printf("INFINITY\n");
		return 0;
	}

	VInt res;
	int i, j;
	FOR(i, 2, 13)
		FOR(j, 0, 1 << i)
		{
			int r = F(i, j, N);
			if(r != -1)
				res.PB(r);
		}

	if(res.empty())
		printf("NONE\n");
	else
	{
		sort(ALL(res));
		FOR(i, 0, SIZE(res))
			printf("%d%c", res[i], i == SIZE(res) - 1 ? '\n' : ' ');
	}

	return 0;
}

int main()
{
	SolveTest();
	return 0;
};

