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
inline void yn(int x) { if(x)co "YES\n"; else co "NO\n"; return; }

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
 

void solve(){
int k[3];
rep(i,0,3) ci k[i];
int n=k[0]+k[1]+k[2];
    vector<int> a(n);
rep(i,0,k[0]){
        int x;ci x;
        a[x - 1] = 0;
    }
rep(i,0,k[1]){
        int x;ci x;
        a[x - 1] = 1;
    }
rep(i,0,k[2]){
        int x;ci x;
        a[x - 1] = 2;
    }
    int ans = 0,bestp = 0;

ans=k[0]+k[1]+k[2]-max({k[0],k[1],k[2]});
vector<int> cntl(3,0),cntr(3,0);

rep(i,0,n) cntr[a[i]]++;

rep(i,0,n){
        cntl[a[i]]++;
        cntr[a[i]]--;
        bestp = max(bestp, cntl[0] - cntl[1]);
        int curans = cntr[0] + cntr[1] + cntl[2] + cntl[0] - bestp;
        ans = min(ans, curans);
    }
    
    cout << ans << endl;
 
  
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

int tc=1;      // cin>> tc; 
while(tc--) { 

solve();

 
}return 0;} 
