#include <bits/stdc++.h>
using namespace std;

#define len(a) ((int)((a).size()))
#define all(a) a.begin(), a.end()
#define mp make_pair
#define fr first
#define sc second
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;

const int N = 505;


void solve(){
 string s;cin>>s;
 int n=s.length();
 int c=0,f=0;
 vector<int> pi(n,0);

rep(i,1,n) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    c=pi[n-1];int cj=c;
    while(c>0){
        cj=c;
        c=pi[c-1];
    }
    //cout<<cj<<endl;
    rep(i,cj,n-1){
        //cout<<pi[i]<<" ";
        if(pi[i]==cj){f=1;break;}
        }
    if(f==0 || cj==0){
        cout<< "Just a legend" ;
    }
    else{
        rep(i,0,cj)cout<<s[i];
    } 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int _ = 1;
	// freopen("", "r", stdin);
	// freopen("", "w", stdout);
	
	// cout << fixed;
	// cout.precision(15);
	
	// cin >> _ ;
	while(_--){
		solve();
	}
	// #ifdef ONPC
		// cerr << "finished in "  << clock() * 1.0 / CLOCKS_PER_SEC << " sec";
	// #endif
	return 0;
}
