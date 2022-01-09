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
    set<int> a, b;
    ll mak = 0, mik = INF;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.insert(x);
        mak = max(mak, x);
        mik = min(mik, x);
    }
    x = mik * mak;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            b.insert(i), b.insert(x / i);
    }
    if (b.size() != n)
    {
        cout << -1 << endl;
        return;
    }
    else if (a == b)
        cout << x << endl;
    else
        cout << -1 << endl;
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
