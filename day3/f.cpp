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

int SolveTest()
{
	int N;
	scanf("%d", &N);

	int i;
	FOR(i, 0, N)
		scanf("%d", &A[i]);

	int Min = 0, Max = (1 << 30);
	while(Max - Min > 1)
	{
		int Mid = (Max + Min) >> 1;

		Int sum = 0;
		FOR(i, 0, N)
			sum += A[i]/Mid;

		if(sum < 8)
			Max = Mid;
		else
			Min = Mid;
	}

	printf("%d\n", Max - 1);
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


