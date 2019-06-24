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

int A[16];

int SolveTest()
{
	int N, K;
	scanf("%d%d", &N, &K);

	int cnt = 0;
	int res = N;
	while (N != 0)
	{
		A[cnt] = N % 10;
		N /= 10;
		++cnt;
	}

	int i, j;
	FOR(i, 1, (1 << cnt))
	{
		int am = 0;
		int t = 0;
		RFOR(j, cnt, 0)
		if ((i & (1 << j)) != 0)
		{
			++am;
			t *= 10;
			t += A[j];
			if (t == 0)
				break;
		}

		if (t == 0 || cnt - am > K)
			continue;

		res = min(res, t);
	}

	printf("%d\n", res);
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};

