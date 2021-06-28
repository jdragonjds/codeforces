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
ll n,m,tot,tmp;  
vector<pii> robber,searchlight;
struct node {
    int a, b;
    bool operator < (const node &q) const {
        return a > q.a;
    }
} p[5000000];




void solve()
{ cin >> n >> m;int ans=oo;int u,v;
rep(i,0,n){ci u>>v;robber.pb({u,v});   }  
rep(j,0,m){ci u>>v;searchlight.pb({u,v}); }
 
rep(i,0,n){
    rep(j,0,m){
        //if(searchlight[j].ff<robber[i].ff && searchlight[j].ss<robber[i].ss )continue;
        if (robber[i].ff <= searchlight[j].ff && robber[i].ss <= searchlight[j].ss) {
                p[++tot] = (node){ searchlight[j].ff -robber[i].ff + 1, searchlight[j].ss -robber[i].ss + 1 };
            }
    }
}

sort(p + 1, p + tot + 1);
for (int i = 1;i <= tot;i++) {
        ans = min(ans, p[i].a + tmp);
        tmp = max(tmp, p[i].b);
    }

DEBUG(min(ans, tmp))
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

int tc=1;       //   cin>> tc; 
while(tc--) { 

solve();

 
}return 0;} 
