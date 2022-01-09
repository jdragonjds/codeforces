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

bool cmp(pii &a, pii &b)
{
    if (a.ff == b.ff)
        return a.ss < b.ss;
    return a.ff > b.ff;
}

void solve(int tc = 0)
{
    cin >> n;
    vector<int> a(n);
    vv(pii) v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.pb({a[i], i});
    }
    cin >> m;
    sort(all(v), cmp);
    vv(vector<int>) res(n + 1);
    rep(i, 0, n)
    {
        res[i + 1] = res[i];
        res[i + 1].pb(v[i].ss);
    }
    rep(i, 0, n)
    {
        sort(all(res[i + 1]));
    }
    rep(i, 0, m)
    {
        int p;
        cin >> x >> p;
        cout << (a[res[x][p - 1]]) << endl;
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
