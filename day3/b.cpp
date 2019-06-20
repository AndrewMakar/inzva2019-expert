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

char buf[1 << 20];

int SolveTest()
{
	int N;
	scanf("%d", &N);

	vector< pair<string, int> > v;

	int i;
	FOR(i, 0, N)
	{
		int a;
		scanf("%s%d", buf, &a);
		v.PB(MP(buf, a));
	}

	int res = 0;
	sort(ALL(v));
	FOR(i, 1, N + 1)
		if(i == N || v[i].first != v[i - 1].first)
			res += v[i - 1].second;

	printf("%d\n", res);

	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


