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
class DisjointSet
{
public:
    vector<int> parent, size;

    DisjointSet(int n) : parent(n + 1), size(n + 1, 1)
    {
        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }

    void join(int a, int b)
    {
        size[find(a)] += size[find(b)];
        size[find(b)] = 0;
        parent[find(b)] = find(a);
    }

    int find(int a) { return a == parent[a] ? a : parent[a] = find(parent[a]); }

    bool check(int a, int b) { return find(a) == find(b); }
};
void solve(int tc = 0)
{
    cin >> n >> k;
    q = k;
    vector<int> a(n);
    DisjointSet dsu(n);
    ans = 1;
    while (q--)
    {
        ans = ans * n % mod;
    }
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y >> z;
        if (z == 0)
        {
            dsu.join(x, y);
        }
    }
    vector<int> res = dsu.size;
    rep(i, 1, n + 1)
    {
        x = 1;
        q = k;
        while (q--)
        {
            x = x * res[i] % mod;
        }
        ans = (ans - x + mod) % mod;
    }
    cout << ans << endl;
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
