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

int A[1 << 17];
int B[1 << 17];
int C[1 << 17];
int R[1 << 17];
int RR[1 << 17];
VInt E[1 << 17];

int SolveTest()
{
	int N, M;
	scanf("%d %d", &N, &M);

	CLEAR(A, 0);
	CLEAR(C, 0);
	
	int i, j, k, l;
	FOR(i, 0, M)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		E[a].PB(b);
		E[b].PB(a);
		++C[a];
		++C[b];
	}

	CLEAR(B, -1);
	FOR(i, 0, N)
		if(B[i] == -1)
		{
			int cnt = 0;
			queue<int> Q;
			Q.push(i);
			B[i] = 0;
			while(!Q.empty())
			{
				int a = Q.front();
				Q.pop();
				++cnt;

				FOR(j, 0, C[a])
				{
					int b = E[a][j];
					if(B[b] == -1)
					{
						B[b] = 0;
						Q.push(b);
					}
				}
			}

			++A[cnt];
		}

	CLEAR(R, 0);
	R[0] = 1;

	FOR(i, 0, N + 1)
		if(A[i] != 0)
		{
			int step = (A[i] + 1)*i;
			FOR(k, 0, i)
			{
				int cnt = 0;
				for(l = k; l <= N; l += i)
				{
					if(R[l] != 0)
						++cnt;
					if(step <= l && R[l - step] != 0)
						--cnt;
					
					RR[l] = (cnt == 0 ? 0 : 1);
				}
			}

			FOR(k, 0, N + 1)
				R[k] = RR[k];
		}

	int res = 0;
	FOR(i, 0, N + 1)
		if(R[i] != 0)
			++res;

	printf("%d\n", res);
	
	FOR(i, 0, N)
		E[i].clear();

	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


