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

void solve(int tc = 0)
{
    cin >> n;
    vector<int> a(n);
    int mik = INF, mak = 0, c = 0;
    int f = 0, ff = 0;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n)
    {
        if (a[i] >= 0)
            if ((i > 0 && a[i - 1] == -1) || (i < n - 1 && a[i + 1] == -1))
            {
                mik = min(mik, a[i]);
                mak = max(mak, a[i]);
            }
        if (a[i] == -1)
            f = 1;
        else
            ff = 1;
    }
    if (ff == 0)
    {
        cout << "0 69\n";
        return;
    }
    else if (f == 0)
    {
        int mak = 0;
        rep(i, 1, n)
        {
            mak = max(mak, abs(a[i] - a[i - 1]));
        }
        cout << mak << " 69\n";
        return;
    }
    z = (mik + mak) / 2;
    m = 0;
    rep(i, 1, n)
    {
        x = (a[i - 1] == -1) ? z : a[i - 1];
        y = (a[i] == -1) ? z : a[i];
        m = max(m, abs(x - y));
    }

    cout << m << " " << z << endl;
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
