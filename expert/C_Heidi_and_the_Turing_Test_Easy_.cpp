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
int cx[60], cy[60];
void solve(int tc = 0)
{
    cin >> n;
    m = n * 4 + 1;
    vector<pii> a;
    int makx = 0, mikx = INF;
    int maky = 0, miky = INF;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        a.pb({x, y});
        makx = max(makx, x);
        mikx = min(mikx, x);
        maky = max(maky, y);
        miky = min(miky, y);
        cx[x]++;
        cy[y]++;
    }
    auto checkx = [&](int u)
    {
        if (u == makx || u == mikx)
            return false;
        return true;
    };
    auto checky = [&](int u)
    {
        if (u == maky || u == miky)
            return false;
        return true;
    };
    vector<pii> ac;
    for (int i = 0; i < m; i++)
    {
        x = a[i].ff, y = a[i].ss;
        if (cx[x] >= n && cy[y] >= n)
        {
            ac.pb({x, y});
            continue;
        }
        else if (cx[x] >= n && checky(y))
            continue;
        else if (cy[y] >= n && checkx(x))
            continue;
        else
        {
            cout << x << " " << y << endl;
            return;
        }
    }
    // only check with cx,cy >=n pair
    rep(i, 0, ac.size())
    {
        x = ac[i].ff, y = ac[i].ss;
        if (x != makx && x != mikx)
            if (y != maky && y != miky)
            {
                cout << x << " " << y << endl;
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
    for (int t = 0; t < tc; t++)
    {
        solve(t + 1);
    }
}
