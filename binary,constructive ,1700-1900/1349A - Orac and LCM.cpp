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
 
const ll N = 2e5+7;
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod=1e9;
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16614;  

 
inline void add(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
} 
 
int lp[N+1];
vector<int> pr;

vector<int> v;  
vector<vector<int>> dp(N);
vector<int>  mdp(N,INT_MAX);

void solve(int tc = 0) { 
    cin>>n; 
    v=vector<int>(n); int g=0;
 rep(i,0,n){ 
cin>>v[i];
g=__gcd(g,v[i]);
 }
 
rep(i,0,n){ 
    int x=v[i]/g; 
    while(x>1){int c=lp[x];int cc=0;
        while(c==lp[x] && c!=0){ x/=c;cc++;}
        dp[c].push_back(cc);mdp[c]=min(mdp[c],cc); 
    }
}
int ans=g;//lp[1]=0
rep(i,2,N){ 
    if(dp[i].size()==n-1){//cout<<i<<" "<<mdp[i]<<endl;
        rep(mmm,0,mdp[i])ans*=i;}
} 
cout<<ans<<endl;
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
   // cin >> tc;   

    for (int i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
    }

    for (int t = 0; t < tc; t++) solve(t);
    
    #ifdef galen_colin_local
        auto end = std::chrono::high_resolution_clock::now();
        cerr << setprecision(4) << fixed;
        cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
    #endif
}
