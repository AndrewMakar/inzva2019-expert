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
int V[256];
int B[256];
int A[256][256];
int E[256][256];
int g_N;

int dfs(int a)
{
	B[a] = 1;
	if(a == g_N - 1)
		return 1;

	int i;
	FOR(i, 0, g_N)
		if(B[i] == 0 && E[a][i] > 0 && dfs(i))
		{
			--E[a][i];
			++E[i][a];
			return 1;
		}

	return 0;
}

int SolveTest()
{
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	int i, j, k;
	FOR(i, 0, N)
		scanf("%d", &V[i]);

	FOR(i, 0, N)
		FOR(j, 0, N)
			A[i][j] = K + 1;

	FOR(i, 0, M)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;

		A[a][b] = A[b][a] = 1;
	}

	FOR(i, 0, N)
		A[i][i] = 0;

	FOR(k, 0, N)
		FOR(i, 0, N)
			FOR(j, 0, N)
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);

	double Min = 0, Max = 1e10;
	FOR(i, 0, 64)
	{
		double Mid = (Max + Min)/2;
		CLEAR(E, 0);

		FOR(j, 0, N)
			FOR(k, 0, N)
				if(A[j][k] <= K)
					E[j][N + k] = N;

		FOR(j, 0, N)
			E[N + N][j] = int(V[j]/Mid);
		FOR(j, 0, N)
			E[j + N][N + N + 1] = 1;

		g_N = N + N + 2;
		int flow = 0;
		while(true)
		{
			CLEAR(B, 0);
			if(!dfs(N + N))
				break;

			++flow;
		}

		if(flow == N)
			Min = Mid;
		else
			Max = Mid;
	}

	printf("%.2lf\n", Min);

	return 0;
}

int main()
{
	SolveTest();
	return 0;
};

