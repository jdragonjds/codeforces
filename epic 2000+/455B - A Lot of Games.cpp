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
inline void yn(int x) { if(x)co "YES\n"; else co "NO\n"; return; }

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
ll gcd(ll u, ll v)//binary gcd
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
ll n,m;  
int timer=0;
struct trie { 
    bool isEndOfWord=false;  
    unordered_map<int, trie*> map;
    int node;
    trie (int curr)
    {
        for (int i = 0; i <26; i++)
            this->map[i] = NULL;
        this->isEndOfWord = false;
        this->node = curr;
    }
}; 
void insert(trie * root , string str){
    trie * p = root;
    for (int i = 0; i < str.size(); i++){
        if (!p->map[str[i] - 'a'])
            p->map[str[i] - 'a'] = new trie(timer++);
        
        p = p->map[str[i] - 'a'];
    }
    p->isEndOfWord = true;
}
vector<bool> win(100005, false), lose(100005, false);
void search(struct trie *root){
    struct trie *pCrawl = root;
    int cnt = 0;
    int node = pCrawl->node;

    for (int i = 0; i < 26; i++)
        if (pCrawl->map[i]) {
            cnt++;
            search(pCrawl->map[i]);
 
            int child = (pCrawl->map[i])->node;
 
            win[node] = win[node] | (!win[child]);
            lose[node] = lose[node] | (!lose[child]);
        }
    if (cnt == 0) lose[node] = true;
}
 
void solve()
{ cin >> n >> m; 
struct trie *root = new trie(timer++);
vector<string> str(n);
rep(i,0,n){
 cin >> str[i];
 insert(root, str[i]); }
search(root);
int node = root->node;
 if (!win[node]) cout << "Second" << endl;
 else if (lose[node]) cout << "First" << endl;
 else if (m % 2) cout << "First" << endl;
 else cout << "Second" << endl;






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
