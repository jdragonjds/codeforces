#include "bits/stdc++.h"
using namespace std;
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define rep(i,x,n) for(long long i = x; i < n; i++)
#define rev(i,x,n) for(long long i = n-1; i >= x; --i)
#define ff            first
#define ss            second
#define int long long
#define pb push_back
#define all(x)  (x).begin() , (x).end()
#define rall(x)  (x).rbegin() , (x).rend()
#define pii pair<long long ,long long >

typedef long long ll;
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
ll n, m, q, k, l, r, x, y , z, target;


vector<vector<int>> g,dis;

void solve(int tc = 0) {
    cin >> n;
    dis=g=vector<vector<int>> (n+1,vector<int>(n+1,0));
    vector<int> id(n+1),ans(n+1,0);
    rep(i,0,n)rep(j,0,n)cin>>g[i+1][j+1];
    rep(i,0,n){
        int x;cin>>x;
        id[x]=n-i;
    }
    rep(i,1,n+1)rep(j,1,n+1)dis[id[i]][id[j]]=g[i][j];
    
    rep(k,1,n+1){
		ans[k] = ans[k - 1];
		rep(i,1,n+1){
			rep(j,1,n+1){
				if(i < k && j < k) ans[k] -= dis[i][j];
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				if(i <= k && j <= k) ans[k] += dis[i][j];
			}
		}
	}
    
    rev(i,1,n+1)cout<<ans[i]<<" ";
}

signed main() {
    send help
    cout << setprecision(9) << fixed;
    int tc = 1;
    //init();
    //cin >> tc;
    for (int t = 0; t < tc; t++) {
        solve(t);
    }
}

