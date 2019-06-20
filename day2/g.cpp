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

int A[1 << 10];

Int gcd(Int a, Int b){ return a == 0 ? b : gcd(b % a, a); }

Int lcm(Int a, Int b){ return a*( b/gcd(a, b) ); }

int Lucky(int a, int b)
{
	int res = 0;
	int i;
	FOR(i, 0, a)
	{
		res *= 10;
		res += (b & (1 << (a - 1 - i))) ? 7 : 4;
	}

	return res;
}

int F(int a, Int b, int pos)
{
	if(a < b || pos == -1)
		return a/b;

	return F(a, b, pos - 1) - F(a, lcm(b, A[pos]), pos - 1);
}

int SolveTest()
{
	int cnt = 0;
	int i, j, k;
	FOR(i, 1, 10)
		FOR(j, 0, 1 << i)
		{
			A[cnt] = Lucky(i, j);
			FOR(k, 0, cnt)
				if(A[cnt] % A[k] == 0)
					break;

			if(k == cnt)
				++cnt;
		}

	int a, b;
	scanf("%d%d", &a, &b);

	int pos = 0;
	while(A[pos] < 10000)
		++pos;

	set<int> Set;
	FOR(i, pos, cnt)
	{
		FOR(j, 0, i)
			if(A[i] % A[j] == 0)
				break;

		if(j < i)
			continue;

		for(j = A[i]; j <= b; j += A[i])
			if(j >= a)
			{
				FOR(k, 0, pos)
					if(j % A[k] == 0)
						break;

				if(k == pos)
					Set.insert(j);
			}
	}

	printf("%d\n", SIZE(Set) + (b - a + 1) - (F(b, 1, pos - 1) - F(a - 1, 1, pos - 1)));
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


