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

int IsLeap(int a)
{
	if(a % 400 == 0)
		return 1;
	if(a % 100 == 0)
		return 0;
	if(a % 4 == 0)
		return 1;
	
	return 0;
}

int SolveTest()
{
	int N;
	scanf("%d", &N);

	int res = (100 - 4 + 1)*(N / 400);
	N %= 400;

	int i, j;
	int Min = N;
	int Max = 0;
	FOR(i,0, 400)
	{
		int temp = 0;
		FOR(j, 0, N)
			if(IsLeap(i + j))
				++temp;

		Min = min(Min, temp);
		Max = max(Max, temp);
	}

	printf("%d %d\n", res + Min, res + Max);
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


