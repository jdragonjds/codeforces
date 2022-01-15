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
const int MOD = 998244353;
const ll INF = 1e15 + 7;
ll n, m, q, k, l, r, x, y, z, ans = 0;
vector<int> pw10;
int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b)
{
    return a * 1ll * b % MOD;
}
int f(int a)
{
    int pos = 0;
    int res = 0;
    while (a > 0)
    {
        int cur = a % 10;
        a /= 10;
        res = add(res, mul(cur, pw10[2 * pos]));
        res = add(res, mul(cur, pw10[2 * pos + 1]));
        ++pos;
    }
    return res;
}
void solve(int tc = 0)
{
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        m = to_string(a).size();
        ans = add(ans, mul(n, f(a)));
    }

    cout << ans << endl;
}

signed main()
{
    send help
            cout
        << setprecision(10) << fixed;
    pw10 = vector<int>(30);
    pw10[0] = 1;
    for (int i = 1; i < 30; ++i)
    {
        pw10[i] = mul(pw10[i - 1], 10);
    }
    int tc = 1;
    for (int t = 0; t < tc; t++)
    {
        solve(t + 1);
    }
}
