#include <iostream>  
#include <sstream>  
#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <memory.h>  
#include <cctype>  
#include <string.h>  
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
#define MAX 250000
#define base 47
#define K 100
 
typedef long long Int;

int n, k, c, p, nn;
char S[MAX];
vector <int> T;
vector <int> I;
int C[22][MAX];
vector < pair < pair<int, int>, int > > Q;
int X[MAX];
int P[MAX];
int J[MAX];
int Y[MAX];
int L[MAX];
Int R[MAX];
int T1[MAX*4];
int T2[MAX*4];
int XX[MAX];
int YY[MAX];
int CC[MAX];
vector <int> PP[MAX];

void Set1(int j, int d, int i, int l, int r)
{
	if (l == r)
		T1[i] = d;
	else
	{
		int m = (l+r)/2;
		if (j <= m)
			Set1(j, d, i*2, l, m);
		else
			Set1(j, d, i*2+1, m+1, r);
		T1[i] = max(T1[i*2], T1[i*2+1]);
	}
}

int Get1(int l, int r, int i, int tl, int tr)
{
	if (l > r)
		return -1;
	if (l == tl && r == tr)
		return T1[i];
	int tm = (tl + tr)/2;
	if (r <= tm)
		return Get1(l, r, i*2, tl, tm);
	if (l > tm)
		return Get1(l, r, i*2+1, tm+1, tr);
	return max(Get1(l, tm, i*2, tl, tm), Get1(tm+1, r, i*2+1, tm+1, tr));
}

void Set2(int j, int d, int i, int l, int r)
{
	if (l == r)
		T2[i] = d;
	else
	{
		int m = (l+r)/2;
		if (j <= m)
			Set2(j, d, i*2, l, m);
		else
			Set2(j, d, i*2+1, m+1, r);
		T2[i] = min(T2[i*2], T2[i*2+1]);
	}
}

int Get2(int l, int r, int i, int tl, int tr)
{
	if (l > r)
		return n;
	if (l == tl && r == tr)
		return T2[i];
	int tm = (tl + tr)/2;
	if (r <= tm)
		return Get2(l, r, i*2, tl, tm);
	if (l > tm)
		return Get2(l, r, i*2+1, tm+1, tr);
	return min(Get2(l, tm, i*2, tl, tm), Get2(tm+1, r, i*2+1, tm+1, tr));
}


bool Cmp(int a, int b)
{
	pair<int, int> aa;
	pair<int, int> bb;

	aa.first = C[p][a];
	aa.second = C[p][(a+n-(1 << p)) % n];
	bb.first = C[p][b];
	bb.second = C[p][(b+n-(1 << p)) % n];

	return aa < bb;
}

bool F(int pos, int x)
{
	int l = -1, r = n;
	if (pos > 0)
		l = Get1(0, x-1, 1, 0, MAX-1);
	if (pos < n-1)
		r = Get2(0, x-1, 1, 0, MAX-1);
	l++;
	r--;
	return (L[r] >= l);
}

int main() 
{
	cin >> n >> k;
	nn = n;
	FOR (i,0,n)
	{
		scanf("%s", S);
		int len = strlen(S);
		FOR (j,0,len)
		{
			J[T.size()] = i;
			CC[T.size()] = len-j;
			T.PB(S[j]-'a');
		}
		J[T.size()] = -1;
		T.PB(INF + i);
	}

	n = T.size();
	FOR (i,0,n)
		Q.PB(MP(MP(T[i], -1), i));
	sort(ALL(Q));
	c = 0;
	FOR (i,0,n)
	{
		if (i > 0 && Q[i].first != Q[i-1].first)
			c++;
		C[0][Q[i].second] = c;
	}

	p = 0;
	while ((1 << (p+1)) <= n)
		p++;

	FOR (i,1,p+1)
	{
		Q.clear();
		c = 0;
		FOR (j,0,n)
			Q.PB(MP(MP(C[i-1][j], C[i-1][(j + (1 << (i-1))) % n]), j));
		sort(ALL(Q));

		FOR (j,0,n)
		{
			if (j > 0 && Q[j].first != Q[j-1].first)
				c++;
			C[i][Q[j].second] = c;
		}
	}
	//FOR (i,0,n)
	//	cout << T[i] << ' ';
	//cout << endl;

	FOR (i,0,n)
		I.PB(i);
	sort(ALL(I), Cmp);

	FOR (i,0,n-1)
	{
		X[i] = 0;
		int a = I[i];
		int b = I[i+1];
		for (int j = p; j>=0; j--)
			if (C[j][a] == C[j][b])
			{
				X[i] += (1 << j);
				a += (1 << j);
				b += (1 << j);
				a %= n;
				b %= n;
			}
	}

	for (int i = n-1; i > 0; i--)
	{
		Y[i] = 0;
		int a = I[i];
		int b = I[i-1];
		for (int j = p; j>=0; j--)
			if (C[j][a] == C[j][b])
			{
				Y[i] += (1 << j);
				a += (1 << j);
				b += (1 << j);
				a %= n;
				b %= n;
			}
	}

	//FOR (i,0,n)
	//	cout << I[i] << ' ';
	//cout << endl;
	//FOR (i,0,n)
	//	cout << J[I[i]] << ' ';
	//cout << endl;
	

	//k++;
	map <int, int> M;

	FOR (i,0,n)
	{
		int id = I[i];
		P[i] = -1;
		if (J[id] == -1)
			continue;	
		if (M.find(J[id]) != M.end())
			P[i] = M[J[id]];
		M[J[id]] = i;
	}

	//FOR (i,0,n)
	//	cout << i << ' ' << J[I[i]] << ' ' << P[i] << endl;

	set <int> S;

	FOR (i,0,n)
	{
		L[i] = -1;
		if (P[i] != -1)
			if (S.find(P[i]) != S.end())
				S.erase(S.find(P[i]));
		//cout << i << '-' << endl;
		S.insert(i);
		while (S.size() > k)
			S.erase(S.begin());
		if (S.size() == k)
			L[i] = *S.begin();
	}

	//FOR (i,0,n)
	//	cout << X[i] << ' ' << Y[i] << ' ' << J[I[i]] << ' ' << L[i] << ' ' << P[i] << endl;

	//FOR (i,0,n)
	//	cout << L[i] << ' ';
	//cout << endl;

	FOR (i,0,MAX*4)
	{
		T1[i] = -1;
		T2[i] = n;
	}

	for (int i = n-1; i>0; i--)
	{
		Set2(Y[i], i, 1, 0, MAX-1);
		PP[Y[i]].PB(i);
	}

	FOR (i,0,n)
	{
		if (i > 0)
		{
			PP[Y[i]].pop_back();
			if (!PP[Y[i]].empty())
			{
				int x = PP[Y[i]].back();
				Set2(Y[i], x, 1, 0, MAX-1);
			}
			else
				Set2(Y[i], n, 1, 0, MAX-1);
		}

		if (J[I[i]] != -1)
		{
			int Min = 1, Max = CC[I[i]];
			while (Min < Max)
			{
				int Mid = (Min + Max)/2;
				if (Min+1 == Max)
					Mid++;
				if (F(i, Mid))
					Min = Mid;
				else
					Max = Mid-1;
			}
  			if (F(i, Min))
				R[J[I[i]]] += Min;
		}

		if (i < n-1)
			Set1(X[i], i, 1, 0, MAX-1);
	}




	FOR (i,0,nn)
	{
		if (i != 0)
			printf(" ");
		printf("%lld", R[i]);
	}
	cout << endl;

	
	
	return 0;
}


