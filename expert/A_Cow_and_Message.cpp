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
    string s;
    cin >> s;
    n = s.size();
    vv(vv(int)) suf(n, vv(int)(26, 0));
    suf[n - 1][s[n - 1] - 'a'] = 1;
    rev(i, 0, n - 1)
    {
        z = s[i] - 'a';
        rep(k, 0, 26)
        {
            suf[i][k] = suf[i + 1][k];
        }
        suf[i][z] = suf[i + 1][z] + 1;
    }
    ans = 0;
    rep(i, 0, 26)
    {
        ans = max(ans, suf[0][i] * 1ll);
    }
    int dp[26][26] = {{0}};
    rep(i, 0, n - 1)
    {
        z = s[i] - 'a';
        rep(j, 0, 26)
        {
            dp[z][j] += suf[i + 1][j];
        }
    }
    rep(i, 0, 26)
    {
        rep(j, 0, 26)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
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
