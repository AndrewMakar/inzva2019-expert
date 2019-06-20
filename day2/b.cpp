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

#define MAX 2600
#define BASE 1000000000000LL
#define STR_OUT "%012lld"
struct Long
{
	Int A[MAX];
	
	Long(Int a = 0)
	{
		CLEAR(A, 0);
		int pos = 0;
		while(a != 0)
		{
			A[pos] = a % BASE;
			a /= BASE;
			++pos;
		}
	}

	void operator *= (Int a)
	{
		int i;
		FOR(i, 0, MAX)
			A[i] *= a;

		FOR(i, 0, MAX - 1)
		{
			A[i + 1] += A[i]/BASE;
			A[i] %= BASE;
		}
	}

	void Out()
	{
		int i;
		RFOR(i, MAX, 1)
			if(A[i])
				break;

		printf("%lld", A[i]);
		RFOR(i, i, 0)
			printf(STR_OUT, A[i]);
	}
};

int C[1 << 17];

int SolveTest()
{
	int N;
	scanf("%d", &N);
	--N;

	CLEAR(C, 0);

	int i, j;
	FOR(i, 1, (N - (N >> 1)) + 1)
		--C[i];
	FOR(i, (N >> 1) + 1, N + 1)
		++C[i];

	Long res = 1;
	RFOR(i, N + 1, 2)
		if(C[i] != 0)
		{
			for(j = 2; j*j <= i; ++j)
				if(i % j == 0)
					break;

			if(j*j <= i)
			{
				C[j] += C[i];
				C[i/j] += C[i];
				C[i] = 0;
			}
			else
				FOR(j, 0, C[i])
					res *= i;
		}

	res.Out();
	printf("\n");

	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


