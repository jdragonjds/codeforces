#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define co cout<< 
#define ci cin>> 
#define rep(i,x,n) for(long long i = x; i < n; i++) 
#define rev(i,x,n) for(long long i = n-1; i >= x; --i)
#define ff            first
#define ss            second 
#define pii pair<long long ,long long > 
#define pb                push_back  
#define all(x)          (x).begin(),(x).end()
#define rall(x)          (x).rbegin(),(x).rend()
#define sz(x)           (x).size() 
#define DEBUG(x) cout << (x) << '\n';
#define LSB(i) ((i) & -(i))
#define int  long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef vector <int> vec;
const ll oo = 1e18;
inline void yn(int x) { if(x)co "YES\n"; else co "NO\n"; return; }

  const int N = 1e5 + 2 ,M=1e6 ,mod=1e9+7,mod1=998244353;
  const int MAXA = 0;const int MAXN = 1e6 + 239; 
 // int mind[MAXA+5]={0};
 /*  
  
int binpow (int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = 1ll * res * a % base;
        a = 1ll * a * a % base;
        n >>= 1;
    }
    return res;
}
 
*/
/*  
ll gcd(ll u, ll v)//binary gcd
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            ll t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}
*/
 
ll n,m,k,ans=0,v[10][N], Pos[10][2000], Best[2000] ;
vector<int> g[2000];
bool Used[2000];
 
void dfs(int z){
    Used[z] = 1;
    for(auto x:g[z]){
        if(!Used[x]) dfs(x);
        Best[z] = max(Best[z],Best[x]+1);
    }
    Best[z] = max(Best[z], 1ll);
    ans = max(ans, Best[z]);
}

void solve()
{ ci n >> k ; 

rep(i,1,k+1) rep(j,1,n+1){ci v[i][j]; Pos[i][v[i][j]]=j;}
 
    rep(i,1,n+1)
        rep(j,1,n+1)
        {if(i==j) continue;
            bool OK = 1;
            for(int kk = 1; kk <= k; ++kk)
                if(Pos[kk][i] >= Pos[kk][j])
                    OK = 0;
            if(OK) g[i].pb(j);
        }
//dp
     ll sol=0;
     rep(j,1,n+1){
        int maxx = 0;
        for(int p = 1;p < j; ++p){
            int i;
            for(i = 2;i <= k && pos[i][v[1][p]] < pos[i][v[1][j]];++i);
            if(i==k+1 && dp[p] > maxx)
                maxx = dp[p];
        }
        dp[j] = maxx+1;
        sol = max(sol,dp[j]);
    }

rep(i,1,n+1) if(!Used[i])dfs(i);
DEBUG(ans)
 
}//solve

signed main(){ fast;  
 /*
for (int i = 2; i * i < MAXA; i++) {
    if (mind[i] == 0) {
      mind[i] = i;
      for (int j = i * i; j < MAXA; j += i) {
        if (mind[j] == 0) {
          mind[j] = i;
        }
      }
    }
  }
 */

int tc=1;      //  cin>> tc; 
while(tc--) { 

solve();

 
}return 0;} 
