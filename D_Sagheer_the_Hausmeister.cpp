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
const ll INF = 1e18 + 7;
ll n, m, q, k, l, r, x, y, z, ans = 0;

void solve(int tc = 0)
{
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(2, INF));

    int top = 0, f = 1;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        rep(j, 0, m + 2)
        {
            if (s[j] == '1')
            {
                f = 0;
                a[i][0] = min(a[i][0], j);
                a[i][1] = j;
            }
        }
        if (f == 1)
            top++;
    }
    vector<vector<int>> dp(n, vector<int>(2, 0));
    if (top == n)
    {
        cout << 0 << endl;
        return;
    }
    dp[top][0] = a[top][1] + 1, dp[top][1] = (m + 1 - a[top][0]) + 1;
    rep(i, top + 1, n)
    {
        if (a[i][0] == INF)
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
            continue;
        }
        dp[i][0] = dp[i - 1][1] + m + 2, dp[i][1] = dp[i - 1][0] + m + 2;
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + 2 * a[i][1] + 1);
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + 2 * (m + 1 - a[i][0]) + 1);
    }
    cout << dp[n - 1][0] - 1 << endl;
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
