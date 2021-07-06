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
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;


 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16614;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

 
inline void add(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}
 
int dp[27][2004];
vector<int> v;

void solve(int tc = 0) {
    cin >> n;int ans=1;
memset(dp,0,sizeof(dp));
v=vector<int> (n+1);
rep(i,1,n+1){
cin>>l;dp[l][i]++;v[i]=l;
} 
rep(i,1,27){
    rep(j,1,n+1)dp[i][j]+=dp[i][j-1]; 
} 
rep(i,1,n+1){int b=v[i];
    rep(a,1,27){int ansi=1;

        int a1=dp[a][i-1];int a2=dp[a][n]-dp[a][i];
        if(a2==0 || a1==0){ans=max(ans,dp[b][n]); 
            continue;}

        int amin=min(a1,a2); 
        ansi=amin*2+1;int cb=1,ca=0; 
        rep(k,i+1,n+1){
            if(v[k]==b)cb++;  if(v[k]==a)ca++;
             
            if(a2-ca<amin)amin=a2-ca; 
            ansi=max(ansi,amin*2+cb);
        }
       //cout<< b<<" "<<ansi<<" "<<ans<<endl;
        ans=max(ansi,ans);
    }
}

cout<<ans<<endl;

}
int main() {
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
    cin >> tc;   
    for (int t = 0; t < tc; t++) solve(t);
    
    #ifdef galen_colin_local
        auto end = std::chrono::high_resolution_clock::now();
        cerr << setprecision(4) << fixed;
        cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
    #endif
}
