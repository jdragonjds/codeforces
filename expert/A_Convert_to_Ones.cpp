// nujabees =>jdragon
#include "bits/stdc++.h"
using namespace std;
#define send                              \
    {                                     \
        ios_base::sync_with_stdio(false); \
    }
#define help           \
    {                  \
        cin.tie(NULL); \
    }
#define getunique(v)                                  \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define rep(i, x, n) for (long long i = x; i < n; i++)
#define rev(i, x, n) for (long long i = n - 1; i >= x; --i)
#define ff first
#define ss second
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vv(x) vector<x>
#define pii pair<long long, long long>
// ctrl + alt + f beautify
typedef long long ll;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
const ll INF = 4e18 + 7;
ll n, m, q, k, l, r, x, y, z, ans = 0;

void solve(int tc = 0)
{
    cin >> n >> x >> y;
    string s;
    cin >> s;
    s = s + '#';
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[i + 1])
            a.pb(s[i] - '0');
    }
    m = (a.size());
    int c0 = 0;
    rep(i, 0, m) if (a[i] == 0) c0++;
    if (c0 == 0)
    {
        cout << 0 << endl;
    }
    else if (y <= x || c0 == 1)
    {
        cout << c0 * y << endl;
    }
    else
    {
        ans = y * c0;
        int dp[c0 + 3] = {0};
        dp[2] = 1;
        ans = min(ans, x + (c0 - 1) * y);
        rep(i, 3, c0 + 1)
        {
            dp[i] = dp[i - 2] + 2;
            ans = min(ans, x * dp[i] + (c0 - i + 1) * y);
        }
        cout << ans << endl;
    }
}

signed main()
{
    send help
            cout
        << setprecision(10) << fixed;
    // init();
    int tc = 1;
    for (int t = 0; t < tc; t++)
    {
        solve(t + 1);
    }
}
