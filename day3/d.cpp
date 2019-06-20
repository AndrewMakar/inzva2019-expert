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

int A[32];
Int R[32][2][32][32];

Int F(int pos, int less, int four, int seven)
{
	if(pos == -1)
		return four == seven ? 1 : 0;

	Int& res = R[pos][less][four][seven];
	if(res != -1)
		return res;

	res = 0;
	int limit = less == 0 ? A[pos] : 9;

	int i;
	FOR(i, 0, limit + 1)
	{
		int less2 = less;
		int four2 = four;
		int seven2 = seven;
		if(i < A[pos])
			less2 = 1;
		if(i == 4)
			++four2;
		if(i == 7)
			++seven2;

		res += F(pos - 1, less2, four2, seven2);
	}

	return res;
}

Int F(Int a)
{
	int i;
	FOR(i, 0, 32)
	{
		A[i] = int(a % 10);
		a /= 10;
	}

	CLEAR(R, -1);
	return F(31, 0, 0, 0);
}

int SolveTest()
{
	Int a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", F(b) - F(a - 1));
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


