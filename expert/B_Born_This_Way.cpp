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
    int ta, tb;
    cin >> n >> m >> ta >> tb >> k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    if (k >= min(n, m))
    {
        cout << -1 << endl;
        return;
    }
    rev(i, 0, min(n, k + 1))
    {
        ll arrival = a[i] + ta;
        auto index = lower_bound(all(b), arrival) - b.begin();
        if (index == m)
        {
            cout << -1 << endl;
            return;
        }
        q = k - i;
        if (index + q >= m)
        {
            cout << -1 << endl;
            return;
        }
        x = index + q;
        ll arrival_at_c = b[x] + tb;
        ans = max(ans, arrival_at_c);
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
