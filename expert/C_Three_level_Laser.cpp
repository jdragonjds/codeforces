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
    vector<int> a(n);
    x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    double res = -1;
    rep(i, 1, n)
    {
        l = a[i] - a[i - 1];
        r = m - l;
        auto index = lower_bound(all(a), a[i] + r + 1) - a.begin();
        index--;
        if (a[index] - a[i - 1] <= m && index > i)
        {
            double dick = (a[index] - a[i]) * 1.0 / (a[index] - a[i - 1]);
            res = max(dick, res);
        }
    }
    if (res == -1)
    {
        cout << -1 << endl;
        return;
    }
    cout << res << endl;
}

signed main()
{
    send help
            cout
        << setprecision(15) << fixed;
    // init();
    int tc = 1;
    for (int t = 0; t < tc; t++)
    {
        solve(t + 1);
    }
}
