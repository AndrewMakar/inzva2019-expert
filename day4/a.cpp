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

pair<Int, Int> egcd(Int a, Int b, Int c)
{
	if (a == 0)
		return pair<Int, Int>(0, c);

	Int k = b / a;
	pair<Int, Int> r = egcd(b - a*k, a, c);

	Int x = r.second - r.first*k;
	Int y = r.first;

	k = x / b;
	x -= k*b;
	y += k*a;

	return pair<Int, Int>(x, y);
}

int SolveTest()
{
	Int K;
	scanf("%lld", &K);

	Int a = 1;
	Int b = 1;
	Int res = 0;
	while (b < K)
	{
		pair<Int, Int> r = egcd(a, b, K);
		Int x = r.first;
		Int y = r.second;

		if (x <= 0)
		{
			x += b;
			y -= a;
		}

		if (y > 0)
			res += (y + a - 1) / a;

		swap(a, b);
		b += a;
	}

	printf("%lld\n", res);
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};

