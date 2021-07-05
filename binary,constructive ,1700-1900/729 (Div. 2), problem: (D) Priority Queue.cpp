#include "bits/stdc++.h"
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define ff first
#define ss second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
 
typedef long long ll; 
typedef long double lld;
typedef unsigned long long ull;
  
// const ll mod = 1000000007;
const ll mod = 998244353; 
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16614;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

ll dp[505][505];
inline void add(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

void solve(int tc = 0) {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') cin >> a[i];
        else a[i] = -1;
    }
    
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] != -1) {
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            for (ll j = 0; j < n; j++) {
                for (ll k = 0; k < n; k++) {
                    // do nothing
                    add(dp[j + 1][k], dp[j][k]);
                    
                    if (j != i) {
                        if (a[j] >= 0) {
                            bool less = (a[j] < a[i] || (a[j] == a[i] && j < i));
                            
                            add(dp[j + 1][k + less], dp[j][k]);
                        } else {
                            if (k > 0) {
                                add(dp[j + 1][k - 1], dp[j][k]);
                            } else if (j < i) {
                                add(dp[j + 1][k], dp[j][k]);
                            }
                        }
                    }
                }
            }
            
            for (ll k = 0; k <= n; k++) {
                ans = (ans + a[i] * dp[n][k]) % mod;
            }
        }
    }
    
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    cout << setprecision(15) << fixed;
     
    int tc = 1;
    // cin >> tc;   
    for (int t = 0; t < tc; t++) solve(t);
   
}
