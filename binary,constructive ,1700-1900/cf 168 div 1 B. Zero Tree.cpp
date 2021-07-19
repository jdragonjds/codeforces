#include "bits/stdc++.h"
using namespace std; 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);} 
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define rep(i,x,n) for(long long i = x; i < n; i++) 
#define rev(i,x,n) for(long long i = n-1; i >= x; --i)
#define ff            first
#define ss            second 
#define int long long 
#define pb push_back
#define all(x)  (x).begin() , (x).end()
#define pii pair<long long ,long long > 
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const ll N = 1e5+7;
const ll mod = 1000000007;
const ll mod1 = 998244353;
ll n, m , k, l, r, x, y, z; 
inline void add(ll& a, ll b) {
    a += b;
    if (a >= mod1) a -= mod1;
} 

vector<int> g[N];
ll v[N];
pii dp[N]; 
 
void dfs (int u, int p) {
  for (int x : g[u]) {
    if (x != p) {
      dfs(x, u);
 
      dp[u].ff = max(dp[u].ff, dp[x].ff);
      dp[u].ss = max(dp[u].ss, dp[x].ss);
    }
  }
 
  v[u] -= dp[u].first;
  v[u] += dp[u].second;
  if (v[u] < 0) {
    dp[u].second += -v[u];
  } else {
    dp[u].first += v[u];
  }
}
 
void solve(int tc = 0) { 
cin >> n;
 
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
 
    g[u].pb(v);
    g[v].pb(u);
  }
 
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
 
  dfs(1, 0);
 
  cout << dp[1].ff + dp[1].ss << endl;

}

signed main() {
    send help      
    cout << setprecision(15) << fixed;
    //init();      
    int tc = 1;
   // cin >> tc;   
    for (int t = 0; t < tc; t++) solve(t); 
}
