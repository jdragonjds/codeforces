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
    vector<set<int>> g(n + 1);
    rep(i, 0, m)
    {
        cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
    }
    set<int> one, two, ex;
    rep(i, 1, n + 1)
    {
        if (g[i].size() == 1)
            one.insert(i);
        else if (g[i].size() == 2)
            two.insert(i);
        else if (g[i].size() > 2)
            ex.insert(i);
    }
    // special cases
    if (two.size() == 4 && one.size() + ex.size() == 0)
    {
        cout << "YES\n";
        return;
    }
    if (one.size() == 4 && two.size() + ex.size() == 0)
    {
        cout << "YES\n";
        return;
    }

    set<int> t;
    for (auto j : ex)
    {
        t.insert(j);
    }
    for (auto j : one)
    {
        for (auto u : g[j])
        {
            t.insert(u);
        }
    }
    if (t.size() > 2)
    {
        cout << "NO\n";
        return;
    }
    for (auto j : two)
    {
        for (auto u : g[j])
        {
            if (one.find(u) == one.end() && two.find(u) == two.end())
            {
                t.insert(u);
            }
        }
    }
    if (t.size() > 2)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
