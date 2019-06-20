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

#define INF ((1 << 30) - 1)

int R[64][64];

int F(int cnt, int digits)
{
	int& res = R[cnt][digits];
	if(res != -1)
		return res;	
	if(cnt == 0)
		return res = 1;
	if(digits == 0)
		return res = 0;

	return res = min(INF, F(cnt - 1, digits) + F(cnt, digits - 1));
}

int SolveTest()
{
	int n;
	scanf("%d", &n);

	CLEAR(R, -1);
	int cnt = 10;
	int i;
	RFOR(i, 64, 0)
	{
		while(F(i, cnt) <= n)
		{
			n -= F(i, cnt);
			--cnt;
		}

		if(cnt != 10)
			printf("%d", 10 - cnt);
	}

	printf("\n");

	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


