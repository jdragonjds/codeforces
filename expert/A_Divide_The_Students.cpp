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
    int a, b, c;
    cin >> a >> b >> c;
    m = a + b + c;
    m = (m + 2) / 3;
    int ca = 0, cc = 0;
    if (a > m)
        ca = a - m;
    if (c > m)
    {
        cc = c - m;
    }
    if (!ca && !cc)
    {
        cout << m << endl;
        return;
    }
    if (cc == 0)
    {
        int ex = m - c;
        b -= min(b, ex);
        cout << max(m, (b + a + 1) / 2) << endl;
        return;
    }
    if (ca == 0)
    {
        int ex = m - a;
        b -= min(b, ex);
        cout << max(m, (b + c + 1) / 2) << endl;
        return;
    }
    if (ca > 0 && cc > 0)
    {
        if (ca >= cc)
        {
            cout << max({m, b + ca, c}) << endl;
            return;
        }
        if (ca < cc)
        {
            cout << max({m, b + cc, a}) << endl;
            return;
        }
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
