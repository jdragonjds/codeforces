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
const int M = 10000 + 7;
int lp[M + 2];
vector<int> pr;
void init()
{
    for (int i = 2; i <= M; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= M; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

void solve(int tc = 0)
{
    cin >> n;
    x = *lower_bound(all(pr), n);
    m = x - n;
    cout << x << endl;
    rep(i, 1, n)
    {
        cout << i << " " << i + 1 << endl;
    }
    cout << n << " " << 1 << endl;
    rep(i, 1, m + 1)
    {
        q = i + m % n;
        if (q == (i + 1) % n)
            q++;
        if (q == 0)
            q = n;
        cout << i << " " << q << endl;
    }
}

signed main()
{
    send help
            cout
        << setprecision(10) << fixed;
    init();
    int tc = 1;
    for (int t = 1; t <= tc; t++)
    {
        solve(t + 1);
    }
}
