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

#define MOD 1234567891

int A[1 << 10];
Int C[1 << 11][1 << 11];
Int R[2][1 << 7][1 << 11];

Int Pow(Int a, Int b)
{
	Int i;
	Int res = 1;
	for (i = 1; i <= b; i <<= 1)
	{
		if ((b & i) != 0)
			res = res * a % MOD;

		a = a * a % MOD;
	}

	return res;
}

int SolveTest()
{
	int N, K;
	scanf("%d%d", &N, &K);

	int i, j, k;
	FOR(i, 0, K)
		scanf("%d", &A[i]);

	sort(A, A + K);
	reverse(A, A + K);

	Int z = 1;
	int prev = 0;
	FOR(i, 1, K + 1)
	if (i == K || A[i] != A[prev])
	{
		FOR(j, 0, i - prev)
			z = z * (j + 1) % MOD;

		prev = i;
	}

	CLEAR(C, 0);
	FOR(i, 0, 1 << 11)
		C[i][i] = C[i][0] = 1;
	FOR(i, 0, 1 << 11)
		FOR(j, 1, i)
		C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;

	CLEAR(R, 0);
	R[0][0][0] = 1;

	FOR(i, 0, K)
	{
		int prev = i & 1;
		int next = prev ^ 1;
		CLEAR(R[next], 0);
		FOR(j, 0, i + 1)
			FOR(k, 0, N + 1)
		if (R[prev][j][k] != 0)
		{
			R[next][j + 1][k + A[i] + A[i] + 1] += (j + 1)*R[prev][j][k];
			R[next][j + 1][k + A[i] + A[i] + 1] %= MOD;

			R[next][j][k + A[i] + 1] += (j + j)*R[prev][j][k];
			R[next][j][k + A[i] + 1] %= MOD;

			if (j > 1)
			{
				R[next][j - 1][k + 1] += (j - 1)*R[prev][j][k];
				R[next][j - 1][k + 1] %= MOD;
			}
		}
	}

	Int res = 0;
	FOR(i, 0, N + 1)
	{
		Int r = R[K & 1][1][i];
		if (r == 0)
			continue;

		Int n = K + 1;
		Int k = N - i;

		r *= C[n + k - 1][k];
		r %= MOD;

		res += r;
	}

	res %= MOD;
	res *= Pow(z, MOD - 2);
	res %= MOD;

	printf("%d\n", int(res));
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};

