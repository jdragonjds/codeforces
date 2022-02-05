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
const int mod = 1e9 + 7;
const ll INF = 4e18 + 7;
int dp[10][2];
void solve(int tc = 0)
{
    ll N;
    cin >> N;

    int zero = 0;
    int one = 1023;
    for (int i = 0; i < N; i++)
    {
        string S;
        int v;
        cin >> S >> v;

        if (S == "|")
        {
            zero |= v;
            one |= v;
        }
        else if (S == "&")
        {
            zero &= v;
            one &= v;
        }
        else if (S == "^")
        {
            zero ^= v;
            one ^= v;
        }
    }
    int vand = 1023, vor = 0, vxor = 0;
    for (int i = 0; i < 10; i++)
    {
        int type = 0;
        // 0 -> 1
        if ((zero >> i) & 1)
            type += 1;
        // 0 -> 0
        else
            ;
        // 1 -> 1
        if ((one >> i) & 1)
            type += 2;
        // 1 -> 0
        else
            ;

        switch (type)
        {
        case 0: // 0,1 -> 0,0   &0
            vand ^= 1 << i;
            break;
        case 1: // 0,1 -> 1,0   ^1
            vxor |= 1 << i;
            break;
        case 2: // 0,1 -> 0,1   0
            break;
        case 3: // 0,1 -> 1,1   |1
        default:
            vor |= 1 << i;
            break;
        }
    }
    cout << 3 << endl;
    cout << "& " << vand << endl;
    cout << "| " << vor << endl;
    cout << "^ " << vxor << endl;
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
