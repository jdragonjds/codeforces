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
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, 0, n)
        rep(j, 0, m)
    {
        cin >> a[i][j];
    }
    rep(b, 0, 11)
    {
        int all = 0;
        int ones = 0;
        vector<int> one(n, 0), zero(n, -1);
        rep(i, 0, n)
        {
            int f = 0, ff = 0;
            rep(j, 0, m)
            {
                if (a[i][j] & (1 << b))
                {
                    f = 1;
                    one[i] = j;
                }
                else
                {
                    ff = 1;
                    zero[i] = j;
                }
            }
            if (f + ff == 2)
                all = 1;
            if (f)
                ones++;
        }
        if (ones % 2 == 0 && all == 0)
            continue;
        cout << "TAK\n";
        if (ones % 2)
        {
            rep(i, 0, n) cout << one[i] + 1 << " ";
            cout << endl;
            return;
        }
        else if (ones % 2 == 0 && ones > 0 && all == 1)
        {
            rep(i, 0, n) if (zero[i] != -1 && a[i][one[i]] & (1 << b))
            {
                one[i] = zero[i];
                break;
            }
            rep(i, 0, n) cout << one[i] + 1 << " ";
            cout << endl;
            return;
        }
    }
    cout << "NIE\n";
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
