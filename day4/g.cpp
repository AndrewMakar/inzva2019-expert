#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forit(i, v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = (int)1E9 + 7;
const ld EPS = 1E-9;
const ld PI = 3.1415926535897932384626433832795;

const int NMAX = 200000;

int n;
vector<int> g[NMAX];

int cnt[NMAX], p[NMAX];

void dfs(int v, int par){
    p[v] = par;
    cnt[v] = 1;
    forn(i, sz(g[v])){
        int u = g[v][i];
        if(u == par) continue;
        dfs(u, v);
        cnt[v] += cnt[u];
    }
}

li choose(li n){
    if(n <= 1) return 0;
    return (n*(n-1))>>1;
}

int getcnt(int v, int u){
    if(u != p[v]) return cnt[u];
    return n - cnt[v];
}

int main() {
    #ifdef myproject
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    #endif

    cin >> n;

    forn(i, n - 1){
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].pb(u);
        g[u].pb(v);
    }

    dfs(0, -1);

    li ans = 0;
    forn(v, n){
        li sum = 0;
        li sum2 = 0;

        forn(i, sz(g[v])){
            int u = g[v][i];
            int curcnt = getcnt(v, u);

//            cerr << curcnt << " ";

            sum += choose(curcnt);
            sum2 += choose(curcnt) * curcnt;
        }
//        cerr << endl;

        li curadd = 0;

        forn(i, sz(g[v])){
            int u = g[v][i];

            int curcnt = getcnt(v, u);

            ans += (sum - choose(curcnt)) * curcnt;

            curadd += (sum - choose(curcnt)) * curcnt;
        }

//        cerr << (v+1) << " " << curadd << endl;
//        cerr << v << " " << ans << " " << sum << endl;


        li add1 = 0;
        forn(i, sz(g[v])){
            int u = g[v][i];
            int curcnt = getcnt(v, u);
            add1 += ((n-1) - curcnt) * li(curcnt);
        }
        assert(add1 % 2 == 0);
        add1 /= 2;

        li add2 = 0;
        forn(i, sz(g[v])){
            int u = g[v][i];
            int curcnt = getcnt(v, u);
            add2 += (sum2 - choose(curcnt) * curcnt) * curcnt;
        }
//        assert(add2 % 2 == 0);
//        add2 /= 2;

        ans += sum * add1 - add2;

        /*
        if(v + 1 == 3){
            cerr << sum << endl;
            cerr << add1 << endl;
            cerr << add2 << endl;
            cerr << (v + 1) << " " << (sum * add1 - add2 * 2) << endl;
        }*/

        /*
        forn(i, sz(g[v])){
            int u1 = g[v][i];
            forn(j, i){
                int u2 = g[v][j];

                int curcnt1 = getcnt(v, u1);
                int curcnt2 = getcnt(v, u2);

                ans += (sum - choose(curcnt1) - choose(curcnt2)) * 1LL * curcnt1 * 1LL * curcnt2;
            }
        }*/

//        cerr << v << " " << ans << endl;
    }

    int z = 0;

    cout << ans << endl;
    return 0;
}


