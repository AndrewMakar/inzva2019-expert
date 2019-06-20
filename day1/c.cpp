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
int I[101][51][34][26];
int B[1 << 18][4];
double R[1 << 18][4];

double F(int a1, int a2, int a3, int a4, int prev)
{
	int a[] = {a1, a2, a3, a4};
	int pos = I[a1][a2][a3][a4];
	double& res = R[pos][prev];
	if(B[pos][prev] != -1)
		return res;

	B[pos][prev] = 0;
	int cnt = a[0] + 2*a[1] + 3*a[2] + 4*a[3] - prev;
	if(cnt == 0)
		return res = prev;

	res = 0;
	int i;
	FOR(i, 0, 4)
	{
		int am = a[i]*(i + 1);
		if(prev == i + 1)
			am -= prev;

		if(am != 0)
		{
			--a[i];
			if(i != 0)
				++a[i - 1];

			res += F(a[0], a[1], a[2], a[3], i)*am;
			
			++a[i];
			if(i != 0)
				--a[i - 1];
		}
	}

	res /= cnt;
	return res;
}

int SolveTest()
{
	int n;
	scanf("%d", &n);
	
	int i, j, k, l;
	FOR(i, 0, n)
	{
		char buf[32];
		scanf("%s%d", buf, &A[i]);
	}

	sort(A, A + n);

	int am[] = {0, 0, 0, 0};
	int prev = 0;
	FOR(i, 1, n + 1)
		if(i == n || A[i] != A[i - 1])
		{
			++am[i - prev - 1];
			prev = i;
		}

	int cnt = 0;
	for(i = 0; i <= n; ++i)
		for(j = 0; i + 2*j <= n; ++j)
			for(k = 0; i + 2*j + 3*k <= n; ++k)
				for(l = 0; i + 2*j + 3*k + 4*l <= n; ++l)
				{
					I[i][j][k][l] = cnt;
					++cnt;
				}

	CLEAR(B, -1);
	printf("%.7lf\n", F(am[0], am[1], am[2], am[3], 0));

	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


