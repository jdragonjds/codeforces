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
const ll INF = 1e15 + 7;
ll n, m, q, k, l, r, x, y, z, ans = 0;

void solve(int tc = 0)
{
    cin >> n >> m;
    vector<int> a(n + 1), pre(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    rep(i, 1, n + 1)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    rep(i, 1, m + 1) dp[i] = pre[i];

    rep(i, m + 1, n + 1)
    {
        dp[i] = dp[i - m] + pre[i];
    }
    rep(i, 0, n)
    {
        cout << dp[i + 1] << " ";
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
