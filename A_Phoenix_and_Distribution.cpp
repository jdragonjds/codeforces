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
    cin >> n >> k;
    vector<string> t(k, "");
    auto r = [&](int i)
    {
        return i % k;
    };
    string s;
    cin >> s;
    vv(int) alpha(26);
    int last = 0;
    rep(i, 0, n)
    {
        alpha[s[i] - 'a']++;
        last = max(last, s[i] - 'a' + 0ll);
    }
    x = 0;
    rep(i, 0, 26)
    {
        int c = 0;
        rep(j, 0, alpha[i])
        {
            if (x >= k)
                break;
            t[r(x)] += 'a' + i;
            x++;
            c++;
        }
        alpha[i] -= c;
        if (x >= k)
            break;
    }
    if (t[0] < t[k - 1])
    {
        cout << t[k - 1] << endl;
        return;
    }
    if (n - x > alpha[last])
    {
        rep(i, 0, 26)
        {
            rep(j, 0, alpha[i])
            {
                t[0] += 'a' + i;
                x++;
            }
        }
        cout << t[0] << endl;
    }
    else
    {
        rep(j, 0, alpha[last])
        {
            t[r(x)] += 'a' + last;
            x++;
        }
        cout << t[r(x - 1)] << endl;
    }
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
