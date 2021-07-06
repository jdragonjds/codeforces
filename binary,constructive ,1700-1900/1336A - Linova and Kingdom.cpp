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
 
const ll N = 1e5+7;
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
 
int nodes[N*2] , depth[N*2];
vector<int> g[N*2];
struct comp {
    bool operator()(pii const& p1, pii const& p2)
    { 
        if(p1.ff==p2.ff){
            //break ties
            return depth[p1.ss] > depth[p2.ss];
        }
        return p1.ff < p2.ff;
    }
};
priority_queue<pii,vector<pii>,comp> pq;

void dfs(int z,int anc=0){ 
    depth[z]=depth[anc]+1;
    for(auto x: g[z]){if(x==anc)continue;
        dfs(x,z);
        nodes[z]+=nodes[x]+1;
    }
    pq.push({depth[z]*nodes[z],z});
}


void solve(int tc = 0) {
    cin>>n>>k;
    rep(i,1,n){int u,v;
        cin>>u>>v;;g[u].push_back(v);g[v].push_back(u);
    }
    depth[0]=0;
    dfs(1); 
    vector<int> tlc,cty(n+1,0);
    int tourist=n-k;  
    while(tourist){
        tourist--;
        tlc.push_back(pq.top().ss);cty[pq.top().ss]=1;
        pq.pop();
    } 
    // now we know which cities are to be made tourist ,now we need to take the problems virginity
    int ans=0;tourist=tlc.size(); 
    rep(i,0,tourist){int j=tlc[i];int f=1; 
        for(auto x: g[j]){ if(depth[x]>depth[j] && cty[x]==0){ans+=(nodes[x]+1)*depth[j];
            //cout<<j<<"-"<<x<<endl; 
             } 
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
    //cin >> tc;   
    for (int t = 0; t < tc; t++) solve(t);
    
    #ifdef galen_colin_local
        auto end = std::chrono::high_resolution_clock::now();
        cerr << setprecision(4) << fixed;
        cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
    #endif
}
