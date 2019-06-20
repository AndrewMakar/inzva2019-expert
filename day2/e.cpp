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

#pragma comment(linker, "/STACK:16777216")

PII P[1 << 17];

PII Parent(int a)
{
	if(P[a].first == a)
		return P[a];

	PII res = Parent(P[a].first);
	res.second += P[a].second;
	P[a] = res;
	return res;
}

int SolveTest()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int i;
	FOR(i, 0, N)
		P[i] = PII(i, 0);

	FOR(i, 0, M)
	{
		char buf[128];
		scanf("%s", buf);
		if(buf[0] == '+')
		{
			int a, b;
			scanf("%d%d", &a, &b);
			--a;
			--b;
			P[a] = PII(b, 1);
		}
		else
		{
			int c;
			scanf("%d", &c);
			--c;
			printf("%d\n", Parent(c).second);
		}
	}

	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


