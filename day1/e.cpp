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

int F(int r1, int c1, int r2, int c2, int n, int m)
{
	if(r1 < r2)
	{
		r1 = n - 1 - r1;
		r2 = n - 1 - r2;
	}

	if(c1 < c2)
	{
		c1 = m - 1 - c1;
		c2 = m - 1 - c2;
	}

	if(r1 == r2 && c1 == c2)
		return 0;
	if(r1 == r2)
		return 2*(c1 - 1);
	if(c1 == c2)
		return 2*(r1 - 1);

	return 2*max(r1 - 1, c1 - 1);
}

int SolveTest()
{
	int N, M, r1, c1, r2, c2;
	scanf("%d%d%d%d%d%d", &N, &M, &r1, &c1, &r2, &c2);
	--r1;
	--c1;
	--r2;
	--c2;

	if((r1 ^ c1 ^ r2 ^ c2) & 1)
	{
		printf("Draw\n");
		return 0;
	}

	if((r1 ^ r2) & 1)
	{
		const int DR[] = {-1, -1, 1, 1};
		const int DC[] = {-1, 1, -1, 1};
		int res = 2*max(N, M);
		for(int i = 0; i < 4; ++i)
		{
			int r = r1 + DR[i];
			int c = c1 + DC[i];

			if(r < 0 || r >= N || c < 0 || c >= M)
				continue;

			res = min(res, F(r, c, r2, c2, N, M) + 1);
		}

		printf("John %d\n", res);
	}
	else
		printf("Brus %d\n", F(r2, c2, r1, c1, N, M));

	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


