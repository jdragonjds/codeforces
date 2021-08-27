#include <bits/stdc++.h>
using namespace std;                       
#define int long long
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define sc second
#define all(v) v.begin(),v.end()
#define piii pair<int, pair<int, int>>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
const ll M = 1e9 + 7;
void findFactor(vector <int> &v, int n){
    set <int> m;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            m.insert(i);
            m.insert(n/i);
        }
    }
    for(auto j : m){
        v.push_back(j);
    }
    return;
}
void solve(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    vector <int> v1;
    vector <int> v2;
    findFactor(v1, n);
    findFactor(v2, m);
    set <string> check;
    for(int i=0;i<v1.size();i++){
        string x = s1.substr(0, v1[i]);
        //cout<<x<<endl;
        string g = "";
        for(int j=0;j<n/v1[i];j++){
            g += x;
        }
        if(g == s1){
            //cout<<x<<endl;
            check.insert(x);
        }
    }
    int cnt = 0;
    for(int i=0;i<v2.size();i++){
        string x = s2.substr(0, v2[i]);
        string g = "";
        //cout<<x<<endl;
        for(int j=0;j<m/v2[i];j++){
            g += x;
        }
        // cout<<g<<endl;
        // if(g == s2){
        //     cout<<x<<endl;
        // }
        if(g == s2 && check.find(x)!=check.end()){
            cnt++;
        }
    }
    cout<<cnt<<endl;

    
    
    
}

signed main(){
    // clock_t time_req;
    // time_req = clock();
    fastio;
    int te;
    //cin>>te;
    te = 1;
    while(te--){
        solve();
    }
    // time_req = clock()-time_req;
    // cout<<"Time taken: "<<(float)time_req/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}
