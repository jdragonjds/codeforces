#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define pb push_back
#define ss second
#define ff first
#define all(v) v.begin(), v.end()
#define deb(...) __logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args> 
void __logger(string vars, Args &&...values) {
    cerr << "\n" << vars << " = ";
    string delim = "";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}
#define w(x) \
    int x;     \
    cin >> x;  \
    while (x--)


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  
    
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    for(string &i: v)
        cin >> i;

    deque<vector<int>> todo;
    todo.push_back({0,0,0});
    vector<vector<int>> distance(n,vector<int>(m,n * m));
    distance[0][0] = 0;
   
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};

    const int sx[9] = {0,0,0,1,-1,1,-1,1,-1};
    const int sy[9] = {0,1,-1,0,0,1,-1,-1,1};

    function<bool(int,int)> isValid = [=](int i,int j) {
        if (i >= 0 && j >= 0 && i < n && j < m)
            return true;
        return false;
    };

    while(!todo.empty()) {
        vector<int> node = todo.front();
        todo.pop_front();
        int cost = node[0],x = node[1],y = node[2];
        // deb(x,y,distance[x][y]);
        if(x == n - 1 && y == m - 1) {
            cout << cost;
            // deb(cost,distance[n - 1][m - 1]);
            break;
        }

        for(int k = 0; k < 4; ++k) {
            int i = x + dx[k],j = y + dy[k];
            if(isValid(i,j)) {
                if(v[i][j] == '#') {
                    for(int p = 0; p < 9; ++p) {
                        int px = i + sx[p],py = j + sy[p];
                        if(isValid(px,py) && distance[px][py] > distance[x][y] + 1) {
                            todo.push_back({cost + 1,px,py});
                            distance[px][py] = distance[x][y] + 1;
                        }
                    }
                }else if(v[i][j] == '.' && distance[i][j] > distance[x][y]){
                    todo.push_front({cost,i,j});
                    distance[i][j] = distance[x][y];
                }
            }
        }

    }

    return 0;
}
