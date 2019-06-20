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

int A[128];
int B[128];
int R[128];

int SolveTest()
{
	int n;
	scanf("%d", &n);

	int i, j;
	FOR(i, 0, n)
		scanf("%d", &A[i]);

	int left = 0;
	int right = n;
	CLEAR(B, 0);
	FOR(i, 0, n)
	{
		int Max = 0;
		FOR(j, 0, n)
			if(B[j] == 0)
				Max = max(Max, A[j]);

		FOR(j, 0, n)
			if(B[j] == 0)
				break;

		if(Max == A[j])
		{
			B[j] = 1;
			R[left] = j;
			++left;
		}
		else
		{
			RFOR(j, n, 0)
				if(B[j] == 0 && A[j] == Max)
					break;

			--right;
			R[right] = j;
			B[j] = 1;
		}
	}

	FOR(i, 0, n)
		printf("%d%c", R[i] + 1, i == n - 1 ? '\n' : ' ');

	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


