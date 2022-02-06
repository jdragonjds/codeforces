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
const ll INF = 4e18 + 7;
ll n, m, q, k, l, r, x, y, z, ans = 0;

void solve(int tc = 0)
{
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;
    vv(int) ca(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        ca[i + 1] = ca[i] + (s[i + 1] == 'a');
    }
    auto chk = [&](int j)
    {
        rep(i, 0, n + 1)
        {
            if (i + j > n)
                break;
            int na = ca[i + j] - ca[i];
            int nb = j - na;
            if (min(nb, na) <= q)
            {
                return true;
            }
        }
        return false;
    };
    l = 1, r = n + 1;
    ans = 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (chk(mid))
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
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
