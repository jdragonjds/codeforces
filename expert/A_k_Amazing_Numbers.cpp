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
const int N = 3e5 + 7;
const int mod = 1e9 + 7;
const ll INF = 1e18 + 7;
ll n, m, q, k, l, r, x, y, z, ans = 0;
vector<int> c[N];
void solve(int tc = 0)
{
    cin >> n;
    vector<int> a(n), b(n + 1, INF);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i]].pb(i + 1);
    }
    rep(i, 1, n + 1)
    {
        if (c[i].size() == 0)
            continue;
        x = 0;
        ll gap = 0, last = 0;
        for (auto u : c[i])
        {
            gap = max(u - last, gap);
            last = u;
        }
        gap = max(n - last + 1, gap);
        b[gap] = min(b[gap], i);
    }
    rep(i, 1, n + 1)
    {
        b[i] = min(b[i], b[i - 1]);
    }
    rep(i, 1, n + 1)
    {
        b[i] == INF ? cout << -1 << " " : cout << b[i] << " ";
    }
    cout << endl;
    rep(i, 0, n)
    {
        c[a[i]].clear();
    }
}

signed main()
{
    send help
            cout
        << setprecision(10) << fixed;
    // init();
    int tc = 1;
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        solve(t + 1);
    }
}
