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

char buf[1 << 17];
int P[1 << 17];

int F(int N)
{
	reverse(buf, buf + N);
	P[0] = P[1] = 0;
	int i;
	FOR(i, 2, N + 1)
	{
		P[i] = P[i - 1];
		while(P[i] != 0 && buf[i - 1] != buf[ P[i] ])
			P[i] = P[ P[i] ];

		if(buf[i - 1] == buf[ P[i] ])
			++P[i];
	}

	reverse(buf, buf + N);
	int res = 0;
	FOR(i, 0, N)
	{
		int pos = N - 1 - res;

		while(res != 0 && buf[i] != buf[pos])
		{
			res = P[res];
			pos = N - 1 - res;
		}

		if(buf[i] == buf[pos])
			++res;
	}

	return res;
}

int SolveTest()
{
	scanf("%s", buf);
	int len = strlen(buf);

	int res = F(len);
	reverse(buf, buf + len);
	res = max(res, F(len));

	printf("%d\n", len - res);
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


