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

int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); }

struct Cmp
{
	int operator()(const PII& a, const PII& b)
	{
		return Int(a.first)*b.second < Int(b.first)*a.second;
	}
};

int SolveTest()
{
	int N, M;
	scanf("%d%d", &N, &M);
	--N;

	priority_queue<PII, vector<PII>, Cmp> Q;
	
	int i;
	FOR(i, 0, N)
	{
		int a;
		scanf("%d", &a);
		Q.push(PII(a, 1));
	}

	FOR(i, 0, M)
	{
		PII a = Q.top();
		Q.pop();
		
		++a.second;
		Q.push(a);
	}

	PII res = Q.top();
	int g = gcd(res.first, res.second);


	printf("%d/%d\n", res.first/g, res.second/g);

	return 0;
}

int main()
{
	SolveTest();
	return 0;
};


