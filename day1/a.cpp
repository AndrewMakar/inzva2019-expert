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

int F(int n, int lucky, int a, int b, int c)
{
	if(a <= c)
		return n*a;

	if(lucky != 0)
		return n*c;

	return (n - 1)*c + min(a, b + c);
}

int SolveTest()
{
	char buf[16];
	int a, b, c;
	scanf("%s%d%d%d", buf, &a, &b, &c);

	int n = strlen(buf);
	int cnt = 0;
	
	int i;
	FOR(i, 0, n)
		if(buf[i] == '4' || buf[i] == '7')
			++cnt;

	printf("%d\n", F(n - cnt, cnt, a, b, c));
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


