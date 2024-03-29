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
#define INF 2000000000   
#define PB push_back   
#define ALL(c) (c).begin(), (c).end()   
#define pi 2*acos(0.0)   
#define SQR(a) (a)*(a)   
#define MP make_pair   
#define MAX 100001 
    
typedef long long Int;   
 
struct RMQ 
{ 
    int len; 
    vector <int> T; 
 
    void Init(int x) 
    { 
        len = x; 
        FOR (i,0,4*x) 
            T.PB(0); 
    } 
 
    void Set(int j, int d, int i, int l, int r) 
    { 
        if (l == r) 
            T[i] = d; 
        else 
        { 
            int m = (l+r)/2; 
            if (j <= m) 
                Set(j, d, i*2, l, m); 
            else 
                Set(j, d, i*2+1, m+1, r); 
            T[i] = max(T[i*2], T[i*2+1]); 
        } 
    } 
 
    int Max(int l, int r, int i, int tl, int tr) 
    { 
        if (l > r) 
            return 0; 
        if (tl == l && tr == r) 
            return T[i]; 
        else 
        { 
            int m = (tl+tr)/2; 
            if (r <= m) 
                return Max(l, r, i*2, tl, m); 
            else 
            if (l > m) 
                return Max(l, r, i*2+1, m+1, tr); 
            else 
                return max(Max(l, m, i*2, tl, m), Max(m+1, r, i*2+1, m+1, tr)); 
        } 
    } 
}; 
 
 
int n, k, len; 
string A[MAX]; 
vector <int> L[MAX]; 
vector <int> R[MAX]; 
vector <int> C4[MAX]; 
vector <int> C7[MAX]; 
int D4[MAX]; 
int D7[MAX]; 
int Q4[MAX]; 
int Q7[MAX]; 
RMQ Q[MAX]; 
 
int F(int a, int b) 
{ 
    int sum = 0; 
    if (a == 0) 
    { 
        FOR (i,0,n) 
        { 
            if (D7[i] < b) 
                return INF; 
            if (Q7[i] >= b) 
                continue; 
            sum += b-Q7[i]; 
        } 
        return sum; 
    } 
    if (b == 0) 
    { 
        FOR (i,0,n) 
        { 
            if (D4[i] < a) 
                return INF; 
            if (Q4[i] >= a) 
                continue; 
            sum += a-Q4[i]; 
        } 
        return sum; 
    } 
    FOR (i,0,n) 
    { 
        int l = lower_bound(ALL(L[i]), a)-L[i].begin(); 
        int r = lower_bound(ALL(R[i]), b)-R[i].begin(); 
        r = A[i].size()-r-1; 
        if (l > r || l >= A[i].size() || r < 0) 
            return INF; 
        int rr = A[i].size()-l-1; 
        int ll = A[i].size()-r-1; 
        int c = lower_bound(C4[i].begin()+l, C4[i].begin()+r+1, a)-C4[i].begin(); 
        int d = lower_bound(C7[i].begin()+ll, C7[i].begin()+rr+1, b)-C7[i].begin(); 
        d = A[i].size()-d-1; 
        if (c <= d) 
            sum += 0; 
        else 
        { 
            if (c > r) 
                c = r; 
            if (d < l) 
                d = l; 
            sum += a + b - Q[i].Max(d, c, 1, 0, Q[i].len-1); 
        } 
    } 
    return sum; 
} 
 
int main() 
{ 
    cin >> n >> k; 
    len = INF; 
    FOR (i,0,n) 
    { 
        cin >> A[i]; 
        int t = A[i].size(); 
        len = min(len, t); 
        Q[i].Init(t); 
        FOR (j,0,t) 
        { 
            int p; 
            p = (A[i][j] != '7'); 
            L[i].PB(p + (j == 0 ? 0 : L[i].back())); 
            p = (A[i][j] == '4'); 
            C4[i].PB(p + (j == 0 ? 0 : C4[i].back())); 
        } 
        R[i].PB(0); 
        C7[i].PB(0); 
        for (int j = t-1; j>=1; j--) 
        { 
            R[i].PB(R[i].back() + (A[i][j] != '4')); 
            C7[i].PB(C7[i].back() + (A[i][j] == '7')); 
        } 
        FOR (j,0,t) 
            Q[i].Set(j, C4[i][j]+C7[i][t-j-1], 1, 0, t-1); 
        D4[i] = 0; 
        FOR (j,0,t) 
            if (A[i][j] != '7') 
                D4[i]++; 
        D7[i] = 0; 
        FOR (j,0,t) 
            if (A[i][j] != '4') 
                D7[i]++; 
        Q4[i] = 0; 
        FOR (j,0,t) 
            if (A[i][j] == '4') 
                Q4[i]++; 
        Q7[i] = 0; 
        FOR (j,0,t) 
            if (A[i][j] == '7') 
                Q7[i]++; 
    } 
    int j = 0; 
    int r = 0, a = 0, b = 0; 
 
    Int res = 0;
 
    for (int i = len; i>=0; i--) 
    { 
        while (j+1 <= len && F(i, j+1) <= k) 
            j++; 
        if (F(i, j) <= k) 
        { 
            res += (j+1);
        } 
    } 
 
     
 
   cout << res-1 << endl;
 
    return 0; 
}    

