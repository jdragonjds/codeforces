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
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> cl(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cl[i] = cl[i - 1];
        if (s[i] == '0')
            cl[i]++;
    }
    auto chk = [&](int j)
    {
        rep(i, 1, n + 1)
        {
            if (s[i] == '1')
                continue;
            int left = max(0ll, i - j - 1);
            int right = min(n, i + j);
            int c = cl[right] - cl[left];

            if (c > k)
            {
                return true;
            }
        }
        return false;
    };
    l = 1, r = n + 1;
    ans = INF;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (chk(mid))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
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
