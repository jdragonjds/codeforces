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
int f(int i)
{
    m = (i + 1) % k;
    if (m == 0)
        return k;
    else
        return m;
}
void solve(int tc = 0)
{
    cin >> n >> k;
    ans = 0;
    string s;
    cin >> s;
    int v[k + 1][26] = {{0}};
    rep(i, 0, n)
    {
        v[f(i)][s[i] - 'a']++;
    }
    q = n / k;
    rep(i, 1, k / 2 + 1)
    {
        int mak = 0;
        rep(j, 0, 26) mak = max(mak, v[i][j] + v[k - i + 1][j]);
        x = q * 2 - mak;
        // cout << i << " " << x << endl;
        ans += x;
    }
    if (k % 2)
    {
        int mak = 0;
        int i = (k + 1) / 2;
        rep(j, 0, 26) mak = max(mak, v[i][j]);
        x = q - mak;
        // cout << i << " " << x << endl;
        ans += x;
    }
    cout << ans << endl;
}

signed main()
{
    send help;
    int tc = 1;
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        solve(t + 1);
    }
}
