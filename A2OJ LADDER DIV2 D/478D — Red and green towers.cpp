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
#define rall(x)  (x).rbegin() , (x).rend()
#define pii pair<long long ,long long >
// ctrl + alt + f beautify
typedef long long ll;
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
ll n, m, q, k, l, r, x, y , z, ans = 0;



void solve(int tc = 0) {
    int red, green;
    cin >> red >> green;
    int dp[2][red + 1];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = red > 0;
    dp[1][0] += green > 0;
    int max_level = 1, ans = 0;
    for (int l = 2; (l * (l + 1)) / 2 <= red + green ; l++) {
        for (int r = red; r >= 0; r--) {
            dp[l % 2][r] = 0;
            bool vis = false;
            if (r >= l and (l * (l + 1)) / 2 - r <= green)
                dp[l % 2][r] += dp[(l + 1) % 2][r - l], vis = true;
            if ((l * (l + 1)) / 2 - r <= green)
                dp[l % 2][r] += dp[(l + 1) % 2][r], vis = true;
            //cout<<dp[l%2][r]<<" ";
            dp[l % 2][r] %= mod;
            if (vis)
                max_level = l % 2;
        }
        //cout<<"\n";
    }
    for (int r = red; r >= 0; r--)
        ans += dp[max_level][r], ans %= mod;
    cout << ans;
}

signed main() {
    send help
    cout << setprecision(9) << fixed;
    int tc = 1;
    //init();
    //cin >> tc;
    for (int t = 0; t < tc; t++) {
        solve(t);
    }
}
