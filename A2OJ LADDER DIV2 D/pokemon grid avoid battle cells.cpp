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
// ctrl + alt + f beautify
typedef long long ll;
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
ll n, m, q, k, l, r, x, y , z, ans = 0;

int ei, ej, si, sj;
int dis[1001][1001], g[1001][1001];


bool isInsideGrid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void avoid_battle( )
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dis[i][j] = INT_MAX;
    int dx[] = { -1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    dis[si][sj] = 0;
    set<pii> st;
    st.insert( {si, sj} );
    while (!st.empty()) {
        auto k = *st.begin();
        st.erase(st.begin());

        for (int i = 0; i < 4; i++)
        {
            int x = k.ff + dx[i];
            int y = k.ss + dy[i];
            if (!isInsideGrid(x, y) || g[x][y]==-1)
                continue;

            if (dis[x][y] > dis[k.ff][k.ss] + g[x][y])
            {  
                dis[x][y] = dis[k.ff][k.ss] + g[x][y];
                st.insert({x, y});
            }
        }
    }

}
 
void solve(int tc = 0) {
    cin >> n >> m ;

    rep(i, 0, n) {
        rep(j, 0, m) {
            char c; cin >> c;

            if (c == 'T')g[i][j] == -1;
            else if (c == 'S')si = i, sj = j;
            else if (c == 'E')ei = i, ej = j;
            else g[i][j] = c - '0';

            if(c=='T')g[i][j]=-1;
           // cout<<g[i][j]<<" ";
        }//cout<<endl;
    }

    avoid_battle();
    cout << dis[ei][ej] << endl;
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
