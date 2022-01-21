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
ll n, m, q, k, l, r, ans = 0;
int make_me_happy[N];
vector<int> g[N];
void dfs(int z, int p = -1)
{
    if (g[z].size() < 2 && z != 1)
    {
        make_me_happy[z] = 1;
        return;
    }
    for (auto x : g[z])
    {
        if (x == p)
            continue;
        dfs(x, z);
        make_me_happy[z] += make_me_happy[x];
    }
}
void solve(int tc = 0)
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> l;
        g[i].pb(l);
        g[l].pb(i);
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    dfs(1);
    vv(int) res;
    rep(i, 1, n + 1)
    {
        res.pb(make_me_happy[i]);
    }
    sort(all(res));
    rep(i, 0, res.size())
    {
        cout << res[i] << " ";
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
