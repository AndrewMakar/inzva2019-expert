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

#define MAX 10
#define INF (1 << 30)

char buf[1 << 20];
string S[32];
int L[32];
pair<int, string> R[32][1 << 10];
int A[32][32];
int B[32][32];

int IsSubString(const string& s, const string& t)
{
	if(SIZE(t) < SIZE(s))
		return 0;

	int i;
	FOR(i, 0, SIZE(t) - SIZE(s) + 1)
		if(t.substr(i, SIZE(s)) == s)
			return 1;

	return 0;
}

int SolveTest()
{
	vector< pair<int, string> > v;
	
	int i, j, k, l;
	FOR(i, 0, MAX)
	{
		scanf("%s", buf);
		string s = buf;
		v.PB(MP(-SIZE(s), s));
	}

	sort(ALL(v));

	int cnt = 0;
	FOR(i, 0, MAX)
	{
		string s = v[i].second;
		string t = v[i].second;
		reverse(ALL(t));

		FOR(j, 0, i)
			if(IsSubString(s, v[j].second) != 0 || IsSubString(t, v[j].second) != 0)
				break;

		if(j == i)
		{
			S[cnt + cnt] = s;
			S[cnt + cnt + 1] = t;
			++cnt;
		}
	}

	FOR(i, 0, cnt + cnt)
		L[i] = SIZE(S[i]);

	FOR(i, 0, cnt + cnt)
		FOR(j, 0, cnt + cnt)
		{
			FOR(k, 1, L[j] + 1)
			{
				if(L[j] - k > L[i])
					continue;

				if(S[i].substr(L[i] - (L[j] - k), L[j] - k) == S[j].substr(0, L[j] - k))
					break;
			}

			A[i][j] = k;
		}

	CLEAR(B, -1);
	FOR(i, 0, cnt + cnt)
	{
		j = i ^ 1;
		FOR(k, 0, L[j] + 1)
			if(S[i].substr(L[i] - (L[j] - k), L[j] - k) == S[j].substr(0, L[j] - k))
			{
				B[i][k] = 0;
				string s = S[i] + S[j].substr(L[j] - k, k);
				FOR(l, 0, cnt + cnt)
					if(IsSubString(S[l], s))
						B[i][k] |= 1 << (l >> 1);
			}
	}

	FOR(i, 0, cnt + cnt)
		FOR(j, 0, 1 << cnt)
			R[i][j] = MP(INF, "");

	pair<int, string> res(INF, "");
	FOR(i, 0, cnt + cnt)
		R[i][1 << (i >> 1)] = MP(L[i], S[i]);

	FOR(j, 0, 1 << cnt)
		FOR(i, 0, cnt + cnt)
			if(R[i][j].first != INF)
			{
				FOR(k, 0, cnt + cnt)
					if((j & (1 << (k >> 1))) == 0)
						R[k][j | (1 << (k >> 1))] = min(R[k][j | (1 << (k >> 1))], MP(R[i][j].first + A[i][k], R[i][j].second + S[k].substr(L[k] - A[i][k], A[i][k])));

				FOR(k, 0, L[i] + 1)
					if(B[i][k] != -1 && (j | B[i][k]) == (1 << cnt) - 1)
					{
						string s = R[i][j].second.substr(0, R[i][j].first - (L[i] - k));
						reverse(ALL(s));
						res = min(res, MP(R[i][j].first + R[i][j].first - (L[i] - k), R[i][j].second + s));
					}
			}

	printf("%s\n", res.second.c_str());
	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


