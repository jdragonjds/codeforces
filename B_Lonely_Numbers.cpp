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
const int M = 1e6 + 7;

vector<int> cprime(M, 1);
void init()
{
    for (long long i = 2; i <= 1e6; i++)
    {
        if (cprime[i])
        {
            for (long long j = i * i; j <= 1e6; j += i)
            {
                cprime[j] = 0;
            }
        }
    }
    for (int p = 2; p < M; p++)
    {
        if (cprime[p] == 1)
        {
            if (p * p < M)
                cprime[p * p]--;
        }
        cprime[p] = cprime[p] + cprime[p - 1];
    }
}
signed main()
{
    send help
            cout
        << setprecision(10) << fixed;
    init();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cout << cprime[x] << endl;
    }
}
