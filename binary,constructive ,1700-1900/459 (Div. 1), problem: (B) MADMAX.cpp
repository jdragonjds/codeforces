#include "bits/stdc++.h"
using namespace std;
 
/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);} 
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define rep(i,x,n) for(long long i = x; i < n; i++) 
#define rev(i,x,n) for(long long i = n-1; i >= x; --i)
#define ff            first
#define ss            second 
#define int long long 
#define pii pair<long long ,long long > 

typedef long long ll;
// typedef int ll;
// #pragma warning("int")
 
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
    cin >> p.first;
    return cin >> p.second;
}
 
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const ll N = 1e5+7;
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;


 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16614;
//ll a[template_array_size];
//ll b[template_array_size];
//ll c[template_array_size];
string s, t;

 
inline void add(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
} 
ll dp[101][101][27],vis[101][101][27];
char c;
vector<pii> g[101];
 
ll dfs(ll a,ll b,ll u)
{
      if(vis[a][b][u])
         return dp[a][b][u];
      vis[a][b][u]=1;
      ll j=0;
      for(auto z: g[a])
      {
         if(z.ss>=u && !dfs(b,z.ff,z.ss))
            j=1;
      }
      dp[a][b][u]=j;
      return j;
}

void solve(int tc = 0) { 
cin>>n>>m;
      rep(i,0,m)
      {
         cin>>x>>y>>c;
         x--;
         y--;
         g[x].push_back({y,c-'a'});
      }
      rep(i,0,n)
      {
         string s="";
         rep(j,0,n)
         {
               if(dfs(i,j,0))
                  s+='A';
               else
                  s+='B';
         }
         cout<<s<<endl;
      }
}
signed main() {
    #ifdef galen_colin_local
        auto begin = std::chrono::high_resolution_clock::now();
    #endif
    
    send help
 
    #ifndef galen_colin_local
        // usaco("code");
    #endif
    
    // usaco("cowland");
    
    // freopen("tc.cpp", "r", stdin);
    // freopen("tc2.cpp", "w", stdout);
        
    cout << setprecision(15) << fixed;


        
    int tc = 1;
    //  cin >> tc;   
    for (int t = 0; t < tc; t++) solve(t);
    
    #ifdef galen_colin_local
        auto end = std::chrono::high_resolution_clock::now();
        cerr << setprecision(4) << fixed;
        cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
    #endif
}
