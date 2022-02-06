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
const int N = 1e6 + 500;
const int mod = 1e9 + 7;
const ll INF = 4e18 + 7;
ll n, m, q, k, l, r, x, y, z, ans = 0;
int dp[N];
void solve(int tc = 0)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        dp[x]++;
    }
    y = 0;
    rep(i, 0, N)
    {
        x = y / 2 + dp[i];
        ans += x % 2;
        y = x - x % 2;
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
