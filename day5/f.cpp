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
  
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i)) 
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i)) 
#define CLEAR(a) memset((a),0,sizeof(a)) 
#define INF 1000000000 
#define PB push_back 
#define ALL(c) (c).begin(), (c).end() 
#define pi 2*acos(0.0) 
#define SQR(a) (a)*(a) 
#define MP make_pair 
#define MAX 5000000
#define base 47
#define MOD 1000000007
 
typedef long long Int;

int n, k;
char S[MAX];
Int F1[MAX];
Int F2[MAX];
int S1[MAX];
int S2[MAX];

int Sum1(int l, int r)
{
	return S1[r] - S1[l-1];
}

int Sum2(int l, int r)
{
	return S2[r] - S2[l-1];
}

int main() 
{
	cin >> n >> k;
	scanf("%s", S);
	for (int i = n-1; i>=0; i--)
		S[i+1] = S[i];

	FOR (i,1,n+1)
	{
		S1[i] = S1[i-1] + (S[i] == 'B');
		S2[i] = S2[i-1] + (S[i] == 'W');
	}

	F1[0] = 1;
	S[0] = S[n+1] = 'X';
	FOR (i,1,n+1)
	{
		int l = i-k+1;
		int r = i;
		int cnt = (S[i] == 'X' ? 2 : 1);

		//cout << cnt << endl;
		F1[i] = Int(F1[i-1])*cnt % MOD;

		if (l > 0)
		{
			int sum = S2[r] - S2[l-1];
			if (sum == 0)
			{
				if (l-2 >= 0 && S[l-1] != 'B')
					F1[i] -= F1[l-2];
				else
				if (l-2 == -1 && S[l-1] != 'B')
					F1[i] -= 1;
				while (F1[i] < 0)
					F1[i] += MOD;
				F1[i] %= MOD;
			}
		}
	}

	F2[n+1] = F2[n+2] = 1;
	for (int i = n; i >= 1; i--)
	{
		int l = i;
		int r = i+k-1;
		int cnt = (S[i] == 'X' ? 2 : 1);

		F2[i] = Int(F2[i+1])*cnt % MOD;

		if (r <= n)
		{
			int sum = S1[r] - S1[l-1];
			if (sum == 0)
			{
				if (S[r+1] != 'W')
					F2[i] -= F2[r+2];
				while (F2[i] < 0)
					F2[i] += MOD;
				F2[i] %= MOD;
			}
		}
	}

	Int cnt = 0, res = 0;

	S[0] = S[n+1] = 'X';
	for (int i = n-k+1; i >= 1; i--)
	{
		int sum = S2[i+k-1] - S2[i-1];
		bool ok = true;
		if (S[i-1] == 'B' || sum != 0)
			ok = false;
		Int r1 = 0;
		if (ok)
		{
			r1 = (i == 1 ? 1 : F1[i-2]);
		}
		int x = i+k;
		Int r2 = 0;
		if (x+k-1 <= n)
		{
			ok = true;
			sum = S1[x+k-1] - S1[x-1];

			if (S[x+k] == 'W' || sum != 0)
				ok = false;
			if (ok)
			{
				r2 = (x+k+1 > n ? 1 : F2[x+k+1]);
			}
		}

		if (i+k <= n && S[i+k] == 'X')
			cnt *= 2;
		cnt += r2;
		cnt %= MOD;
		res += r1*cnt;
		res %= MOD;

		//cout << r1 << ' ' << r2 << ' ' << cnt << endl;
	}

	cout << res % MOD << endl;


	return 0;
}
