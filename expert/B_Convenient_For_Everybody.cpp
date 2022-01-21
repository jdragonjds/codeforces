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
int s, f;
int ufc(int x)
{
    return ((x + n) % n ? (x + n) % n : n);
}
void solve(int tc = 0)
{
    cin >> n;
    vector<int> a(n + 1), ps(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    cin >> s >> f;
    q = f - s;
    x = ps[q];
    int hour = n;
    vv(int) res;
    rep(i, 1, n + 1)
    {
        if (ans < x)
        {
            ans = x;
            res.clear();
            res.pb(i);
        }
        else if (ans == x)
        {
            ans = x;
            res.pb(i);
        }
        x += a[ufc(i + q)] - a[i];
    }

    for (auto i : res)
        hour = min(hour, ufc(s - i + 1));
    cout << hour << endl;
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
