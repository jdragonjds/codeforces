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
ll n, m, q, k, l, r, x, y, z, ans = INF;

void solve(int tc = 0)
{
    cin >> n >> l;
    vector<ll> c(32, INF);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    rep(i, 1, 32)
    {
        x = c[i - 1] * 2;
        c[i] = min(x, c[i]);
    }
    ll mask = 0, cur = 0;
    rev(i, 0, 32)
    {
        if ((1ll << i) >= l)
            ans = min(ans, c[i]);
        if (cur + (1ll << i) >= l)
            ans = min(ans, mask + c[i]);
        if ((1ll << i) & l)
        {
            mask += c[i], cur += (1ll << i);
        }
    }
    cout << ans << endl;
}

signed main()
{
    send help
            cout
        << setprecision(10) << fixed;
    solve(1);
}
