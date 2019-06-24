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
#include <time.h>
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

const int INF = 1000000000;
const int MAX = 64;
const int MAX2 = 7000;
const int BASE = 1000000000;
const int CNT = 10;
const int MOD = 1000000007;

int n, a, b;
int A[MAX];
int W[MAX];
vector <PII> Q;
vector <Int> M;

int main()
{

    scanf("%d %d %d", &n, &a, &b);
    FOR (i,0,n)
        scanf("%d", &A[i]);

    int pos = 0;
    while (pos < n)
    {
        if (A[pos] < a || A[pos] > b)
        {
            ++ pos;
            continue;
        }
        int add = 1;
        while (pos+add < n && A[pos+add] >= a && A[pos+add] <= b)
            ++ add;
        if (add == 1)
            W[A[pos]-a] = 1;
        else
        {
            Int mask = 0;
            FOR (i,pos,pos+add)
                mask |= (1LL << (A[i]-a));
            Q.PB(MP(pos, pos+add-1));
            M.PB(mask);
        }
        pos += add;
    }
    int len = (b-a+1);
    int res = INF;
    FOR (mask,0,(1 << SZ(Q)))
    {
        int cnt = 0;
        Int used = 0;
        FOR (i,0,SZ(Q))
            if ((mask & (1 << i)) != 0)
            {
                used |= M[i];
                ++ cnt;
            }
        bool was = 0;
        FOR (i,0,len)
            if ((used & (1LL << i)) == 0)
            {
                if (W[i] == 0)
                    was = 1;
                else
                    ++ cnt;
            }
        if (was == 0)
            res = min(res, cnt);
    }
    printf("%d\n", res >= INF ? -1 : res);






    return 0;
}


