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
const int oo = 1e18 + 7;
ll n, m, k, s, x, y, z;
vector<int> g[N];
vector<int> goods[150];
vector<vv(int)> ans(N, vv(int)(150, oo));
int dist[N];
void solve(int tc = 0)
{
    cin >> n >> m >> k >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        goods[x].push_back(i + 1);
    }
    rep(i, 0, m)
    {
        cin >> x >> y;
        g[x].pb(y), g[y].pb(x);
    }
    rep(i, 1, k + 1) // item
    {
        queue<int> q;
        for (auto town : goods[i])
        {
            ans[town][i] = 0;
            q.push(town);
        }
        while (q.size())
        {
            auto town = q.front(); // town of good_i
            q.pop();
            for (int c_town : g[town])
            {
                if (ans[c_town][i] <= ans[town][i] + 1)
                    continue;
                ans[c_town][i] = ans[town][i] + 1;
                q.push(c_town);
            }
        }
    }
    rep(i, 1, n + 1)
    {
        int res = 0;
        sort(all(ans[i]));
        for (int j = 0; j < s; j++)
            res += ans[i][j];
        cout << res << " ";
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
