#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define co cout<< 
#define ci cin>> 
#define rep(i,x,n) for(long long i = x; i < n; i++) 
#define rev(i,x,n) for(long long i = n-1; i >= x; --i)
#define ff            first
#define ss            second 
#define pii pair<long long ,long long > 
#define pb                push_back  
#define all(x)          (x).begin(),(x).end()
#define rall(x)          (x).rbegin(),(x).rend()
#define sz(x)           (x).size() 
#define DEBUG(x) cout << (x) << '\n';
#define LSB(i) ((i) & -(i))
#define int  long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef vector <int> vec;
const ll oo = 1e18;
inline void yn(int x) { if(x)co "OBEY\n"; else co "REBEL\n"; return; }

  const int N = 1e5 + 2 ,M=1e6 ,mod=1e9+7,mod1=998244353;
  const int MAXA = 0;const int MAXN = 1e6 + 239; 
 // int mind[MAXA+5]={0};
 /*  
  
int binpow (int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = 1ll * res * a % base;
        a = 1ll * a * a % base;
        n >>= 1;
    }
    return res;
}
 
*/
/*  
ll gcd(ll u, ll v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            ll t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}
*/
int n;
int a[MAXN];
namespace SegmentTree {
    int n;
    ll t[4 * MAXN];
    ll mod[4 * MAXN];

    void pull(int v) {
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }

    void apply(int v, ll val) {
        t[v] += val;
        mod[v] += val;
    }

    void push(int v) {
        if (mod[v] != 0) {
            apply(2 * v + 1, mod[v]);
            apply(2 * v + 2, mod[v]);
            mod[v] = 0;
        }
    }

    void build(int v, int l, int r) {
        if (l + 1 == r) {
            t[v] = a[l];
        } else {
            int m = (r + l) >> 1;
            build(2 * v + 1, l, m);
            build(2 * v + 2, m, r);
            pull(v);
        }
    }

    void add(int v, int l, int r, int ql, int qr, ll val) {
        if (r <= ql || qr <= l) {
            return;
        } else if (ql <= l && r <= qr) {
            apply(v, val);
        } else {
            push(v);
            int m = (r + l) >> 1;
            add(2 * v + 1, l, m, ql, qr, val);
            add(2 * v + 2, m, r, ql, qr, val);
            pull(v);
        }
    }

    int go_down(int v, int l, int r) {
        if (l + 1 == r) {
            return l;
        } else {
            push(v);
            int m = (r + l) >> 1;
            int res = -1;
            if (t[2 * v + 2] == 0) {
                res = go_down(2 * v + 2, m, r);
            } else {
                res = go_down(2 * v + 1, l, m);
            }
            pull(v);
            return res;
        }
    }

    void init(int n_) {
        n = n_;
        build(0, 0, n);
    }

    void add(int l, int r, ll val) {
        add(0, 0, n, l, r, val);
    }

    void add(int pos, ll val) {
        add(0, 0, n, pos, pos + 1, val);
    }

    int last_zero() {
        return go_down(0, 0, n);
    }
}

void solve(){
cin >> n;  
rep(i,0,n){ci a[i]; }
SegmentTree::init(n);
    vector<int> ans(n, -1);
    for (int i = 1; i <= n; i++) {
        int pos = SegmentTree::last_zero();
        ans[pos] = i;
        SegmentTree::add(pos, oo);
        SegmentTree::add(pos + 1, n, -i);
    }
    for (auto t : ans) {
        cout << t << ' ';
    }
    cout << endl;
}//solve

signed main(){ fast;  
 /*
for (int i = 2; i * i < MAXA; i++) {
    if (mind[i] == 0) {
      mind[i] = i;
      for (int j = i * i; j < MAXA; j += i) {
        if (mind[j] == 0) {
          mind[j] = i;
        }
      }
    }
  }
 */

int tc=1;      //  cin>> tc; 
while(tc--) { 

solve();

 
}return 0;} 
