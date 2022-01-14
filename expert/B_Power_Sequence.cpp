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
    cin >> n;
    vector<int> a(n);
    x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        x += abs(a[i] - 1);
    }
    sort(all(a));
    vector<int> pi(n, 1);
    auto p = [&](int u)
    {
        rep(i, 1, n)
        {
            pi[i] = pi[i - 1] * u;
            if (pi[i] > x + q)
                return true;
        }
        return false;
    };
    q = a[n - 1];
    ans = INF;
    for (int i = 1; i <= N; i++)
    {
        if (p(i))
            break;
        z = 0;
        rep(j, 0, n)
        {
            z += abs(pi[j] - a[j]);
        }
        ans = min(ans, z);
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
