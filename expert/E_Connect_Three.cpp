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
int p[3][2];
int man(int a, int b, int c, int d)
{
    return abs(a - c) + abs(b - d);
}
int man3(int a, int b)
{
    ll res = 0;
    rep(i, 0, 3)
        res += abs(a - p[i][0]) + abs(b - p[i][1]);
    return res;
}
int tx, ty;
int tile[1011][1011];
void dfs(int cx, int cy)
{
    if (cx == tx && cy == ty)
        return;
    rev(dx, -1, 2) rep(dy, -1, 2)
    {
        if (dx == dy)
            continue;
        if (man(cx + dx, cy + dy, tx, ty) < man(cx, cy, tx, ty))
        {
            if (tile[cx + dx][cy + dy] == 0)
            {
                tile[cx + dx][cy + dy] = 1;
            }
            dfs(cx + dx, cy + dy);
            return;
        }
    }
}
void solve(int tc = 0)
{

    int sx = 0, sy = 0;
    tx = INF, ty = INF;
    rep(j, 0, 3)
    {
        cin >> p[j][0] >> p[j][1];
        sx = max(sx, p[j][0]);
        sy = max(sy, p[j][1]);
        tx = min(tx, p[j][0]);
        ty = min(ty, p[j][1]);
    }
    cout << sx - tx + sy - ty + 1 << endl;
    ans = INF;

    rep(u, 0, 1001)
        rep(v, 0, 1001)
    {
        q = man3(u, v);
        if (q < ans)
        {
            ans = q;
            x = u;
            y = v;
        }
    }
    tile[x][y] = 1;
    rep(j, 0, 3)
    {
        tx = p[j][0], ty = p[j][1];
        dfs(x, y);
    }

    rep(i, 0, 1001)
    {
        rep(j, 0, 1001)
        {
            if (tile[i][j])
                cout << i << " " << j << endl;
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
