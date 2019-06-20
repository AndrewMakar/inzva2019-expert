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

#define INF 1000000001

PII A[128];
int B[128];
int C[128];
int Res[4][26][34][51][101];
map<int, int> Map;

int F(int c1, int c2, int c3, int c4, int prev)
{
	int& res = Res[prev][c4][c3][c2][c1];
	if(res != -1)
		return res;
	if((c1 | c2 | c3 | c4) == 0)
		return res = 1;

	res = 0;
	int c[] = {0, c1, c2, c3, c4};
	int i;
	FOR(i, 1, 5)
	{
		int cnt = c[i];
		if(prev == i)
			--cnt;

		if(cnt == 0)
			continue;

		cnt *= i;
		--c[i];
		++c[i - 1];

		res = min(INF, res + int(min(Int(INF), Int(cnt)*F(c[1], c[2], c[3], c[4], i - 1))));

		--c[i - 1];
		++c[i];
	}

	return res;
}

int SolveTest()
{
	const string Colors = "YBGR";

	int N, K;
	scanf("%d%d", &N, &K);

	int i, j;
	FOR(i, 0, N)
	{
		char buf[128];
		scanf("%s", buf);
		A[i].second = find(ALL(Colors), buf[0]) - Colors.begin();
		sscanf(buf + 1, "%d", &A[i].first);
	}

	sort(A, A + N);

	CLEAR(B, 0);
	CLEAR(C, 0);
	Map.clear();

	FOR(i, 0, N)
		Map[ A[i].first ] = 0;

	FOR(i, 0, N)
	{
		--C[ Map[ A[i].first ] ];
		++Map[ A[i].first ];
		++C[ Map[ A[i].first ] ];
	}

	CLEAR(Res, -1);
	if(F(C[1], C[2], C[3], C[4], 0) < K)
	{
		printf("NONE\n");
		return 0;
	}

	int prev = -1;
	FOR(i, 0, N)
	{
		if(i != 0)
			printf("-");

		RFOR(j, N, 0)
			if(B[j] == 0 && A[j].first != prev)
			{
				--C[ Map[ A[j].first ] ];
				--Map[ A[j].first ];
				++C[ Map[ A[j].first ] ];

				int cnt = F(C[1], C[2], C[3], C[4], Map[ A[j].first ]);
				if(cnt >= K)
				{
					B[j] = 1;
					prev = A[j].first;
					printf("%c%d", Colors[ A[j].second ], A[j].first);
					break;
				}
				else
					K -= cnt;

				--C[ Map[ A[j].first ] ];
				++Map[ A[j].first ];
				++C[ Map[ A[j].first ] ];
			}
	}

	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


