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

#define INF (1 << 30)
#define MAX (1 << 16)
int R[MAX];

int SolveTest()
{
	VInt v;
	int i, j;
	FOR(i, 1, 21)
	{
		v.PB(i);
		v.PB(i + i);
		v.PB(i + i + i);
	}

	v.PB(25);
	v.PB(50);

	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());

	int n= SIZE(v);
	FOR(i, 0, MAX)
		R[i] = INF;

	R[0] = 0;
	FOR(i, 0, MAX)
		FOR(j, 0, n)
			if(i + v[j] < MAX)
				R[i + v[j]] = min(R[i + v[j]], R[i] + 1);

	int res = 0;
	int m;
	scanf("%d", &m);
	if(m >= MAX)
	{
		int pos = MAX - 1;
		while((m - pos) % v[n - 1] != 0)
			--pos;

		res += (m - pos)/v[n - 1];
		m = pos;
	}

	res += R[m];
	printf("%d\n", res);
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


