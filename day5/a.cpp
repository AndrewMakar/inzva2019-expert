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

int Mask[128];
int Res[1 << 20];

int Count(int a){ return a == 0 ? 0 : Count(a >> 1) + (a & 1); }

int SolveTest()
{
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	int i, j, k;
	FOR(i, 0, K)
	{
		int C;
		scanf("%d", &C);
		Mask[i] = 0;
		FOR(j, 0, C)
		{
			scanf("%d", &k);
			Mask[i] |= 1 << (k - 1);
		}
	}

	CLEAR(Res, -1);
	Res[0] = 0;

	queue<int> Q;
	Q.push(0);
	while(!Q.empty())
	{
		int a = Q.front();
		Q.pop();

		if(Count(a) >= M)
		{
			printf("%d\n", Res[a]);
			return 0;
		}

		FOR(i, 0, K)
			if(Res[ a ^ Mask[i] ] == -1)
			{
				Res[ a ^ Mask[i] ] = Res[a] + 1;
				Q.push(a ^ Mask[i]);
			}
	}

	printf("-1\n");
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};

