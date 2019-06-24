#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility> 
using namespace std;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 2000000000;
const int MAX = 512;
const int MAX2 = 1007;
const int BASE = 1000000000;

const int MOD = 1000000007;

int n;
int C[3];
int S[MAX];
VI G[MAX];
VI V[MAX];
Int R1[3][MAX][MAX];
Int R2[3][MAX][MAX];
Int T[MAX];
Int Bin[MAX][MAX];

void dfs1(int v, int p)
{
	S[v] = 1;
	FOR (i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p)
			continue;
		dfs1(to, v);
		V[v].PB(to);
		S[v] += S[to];
	}
}

void dfs2(int v, int color)
{
	R1[color][v][0] = 1;
	int sum = 0;
	FOR (i,0,SZ(V[v]))
	{
		int to = V[v][i];
		dfs2(to, color);
		FILL(T, 0);
		FOR (j,0,sum+1)
			T[j] = R1[color][v][j];
		FILL(R1[color][v], 0);
		RFOR (j,sum+1,0)
		{
			Int cur = T[j];
			// place 'color'
			FOR (k,0,min(C[color]-1, S[to])+1)
			{
				R1[color][v][j+k+1] += cur * R1[color][to][k];
				R1[color][v][j+k+1] %= MOD;
			}
			// place not 'color'
			FOR (k,0,S[to]+1)
			{
				R1[color][v][j+k] += cur * R1[color][to][k];
				R1[color][v][j+k] %= MOD;
			}
		}
		sum += S[to];
	}
}

void dfs3(int v, int color)
{
	R2[color][v][0] = 1;
	int sum = 0;
	FOR (i,0,SZ(V[v]))
	{
		int to = V[v][i];
		dfs3(to, color);
		FILL(T, 0);
		FOR (j,0,sum+1)
			T[j] = R2[color][v][j];
		FILL(R2[color][v], 0);
		RFOR (j,sum+1,0)
		{
			Int cur = T[j];
			// place 'color'
			FOR (k,0,S[to]+1)
			{
				R2[color][v][j+k+1] += cur * R2[color][to][k];
				R2[color][v][j+k+1] %= MOD;
			}
			// place not 'color' 1
			FOR (other,0,3)
			{
				if (other == color)
					continue;
				int third = -1;
				FOR (k,0,3)
					if (k != color && k != other)
						third = k;
				FOR (k,0,S[to]+1)
				{
					Int cntWays = R1[third][to][k];
					int cntThird = k;
					int cntOther = S[to] - k;
					FOR (w,0,cntOther)
					{
						if (cntOther-w > C[other])
							continue;
						Int u = cur * Bin[cntOther-1][w];
						u %= MOD;
						u *= cntWays;
						u %= MOD;
						R2[color][v][j+w] += u;
						R2[color][v][j+w] %= MOD;
					}
				}
			}
		}
		sum += S[to];
	}
}

bool ok;
int Q[MAX];
int W[MAX][3];

void dfs4(int v)
{
	W[v][Q[v]] ++;
	FOR (i,0,SZ(V[v]))
	{
		int to = V[v][i];
		dfs4(to);
		FOR (j,0,3)
			W[v][j] += W[to][j];
	}
	if (W[v][Q[v]] > C[Q[v]])
		ok = 0;
}

int Brute()
{
	int res = 0;
	int p = 1;
	FOR (i,0,n)
		p *= 3;
	FOR (mask,0,p)
	{
		FILL(Q, 0);
		int pos = 0;
		int x = mask;
		while (x > 0)
		{
			Q[pos ++] = x % 3;
			x /= 3;
		}
		FILL(W, 0);
		ok = 1;
		dfs4(0);
		res += ok;
	}
	return res;
}

int main()
{
	//freopen("in.txt", "r", stdin);

	FOR (i,0,MAX)
		Bin[i][0] = 1;
	FOR (i,1,MAX)
		FOR (j,1,i+1)
			Bin[i][j] = (Bin[i-1][j] + Bin[i-1][j-1]) % MOD;

	scanf("%d %d %d %d", &n, &C[0], &C[1], &C[2]);
	FOR (i,0,n-1)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		-- u;
		-- v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs1(0, -1);
	FOR (color,0,3)
		dfs2(0, color);
	Int res = 0;
	FOR (color,0,3)
	{
		dfs3(0, color);
		FOR (i,0,C[color])
		{
			res += R2[color][0][i];
			res %= MOD;
		}
	}
	printf("%d\n", res);


	

	return 0;
}
