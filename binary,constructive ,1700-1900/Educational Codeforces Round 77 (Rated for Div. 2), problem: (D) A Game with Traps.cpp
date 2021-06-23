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
#define int long long 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef vector <int> vec;
const ll oo = 1e18;
inline void yn(int x) { if(x)co "OBEY\n"; else co "REBEL\n"; return; }

  const int N = 1e5 + 2 ,M=1e6 ,mod=1e9+7,mod1=998244353;
  const int MAXA = 0; 
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
ll gcd(ll u, ll v)
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
vector<int> a,l,r,d;
int m,n,k,t;
int zero=0;
bool can(int x){ int mn = a[x-1]; 
 vector<pii> trap;
rep(i,0,k )if (d[i] > mn) trap.pb({l[i], r[i]});
int jacob_collier=0,lastr = 0;
for(auto s:trap){
    if (s.ff <= lastr){
        jacob_collier += max(zero, s.ss - lastr);
        lastr = max(s.ss, lastr);
    }
    else
    {
        jacob_collier += s.ss - s.ff + 1;
        lastr = s.ss;
    }
}
jacob_collier = 2 * jacob_collier + n + 1;
return jacob_collier <= t;
}


void solve(){
ci m>>n>>k>>t;
a.resize(m); l.resize(k); r.resize(k); d.resize(k);
rep(i,0,m)ci a[i];
sort(rall(a));
rep(i,0,k ){ ci l[i]>>r[i]>>d[i]; }
 
int lf = 0;
    int rg = m + 1;
    while (rg - lf > 1)
    {
        int mid = (lf + rg) / 2;
        if (can(mid))
            lf = mid;
        else
            rg = mid;
    }
DEBUG(lf)

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
