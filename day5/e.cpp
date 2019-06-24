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
typedef long double Double;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<string,string> PSS;
typedef vector<int> VInt;
typedef vector<double> VDouble;
typedef vector<string> VString;
typedef vector<char> VChar;
typedef vector<Int> VLong;

#define FOR(i, a, b) for(i = a; i < b; i++)
#define RFOR(i, a, b) for(i = a - 1; i >= b; i--)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOREACH(i, a) for(i = (a).begin(); i != (a).end(); i++)
#define RFOREACH(i, a) for(i = (a).rbegin(); i != (a).rend(); i++)
#define PB push_back
#define MP make_pair

#define min(a, b) ((a < b) ? (a) : (b))
#define max(a, b) ((a > b) ? (a) : (b))
/************************************************************/

int SolveTest()
{
	int N;
	scanf("%d", &N);
	--N;

	Int res = 0;
	int i;
	RFOR(i, 30, 0)
	{
		res *= 3;
		if(N & (1 << i))
			++res;
	}

	printf("%lld\n", res + 1);
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};

