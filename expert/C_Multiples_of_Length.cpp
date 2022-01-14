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
void bullshit_number_theory_problem(int x)
{
    cout << "1 1\n";
    cout << -x << endl;
}
void solve(int tc = 0)
{
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bullshit_number_theory_problem(a[0]);
    a[0] = 0;
    if (n == 1)
    {
        bullshit_number_theory_problem(0);
        bullshit_number_theory_problem(0);
        exit(0);
    }
    cout << 2 << " " << n << "\n";
    rep(i, 1, n)
    {
        cout << (n - 1) * a[i] << " ";
    }
    cout << "\n";
    cout << 1 << " " << n << "\n";
    rep(i, 0, n)
    {
        cout << -(n)*a[i] << " ";
    }
}

signed main()
{
    solve(45);
}
