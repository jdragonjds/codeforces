#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;
#define all(m) m.begin(),m.end()
#define sz(m) lld(m.size())
#define pb push_back
#define mod 1000000007
#define st first
#define nd second
// #define endl "\n"

#ifdef LOCAL
    #define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(...) 
#endif

const int N=3e5+7;
const int LOGN=log2(N)+7;
vector<lld> gold(N),cost(N);
lld anc[N+7][LOGN+7];

void swagWaalaFunction()
{
    lld q;
    cin>>q>>gold[0]>>cost[0];

    for(int ii=1;ii<=q;ii++)
    {
        lld t;
        cin>>t;

        if(t==1)
        {
            lld p,a,c;
            cin>>p>>a>>c;

            gold[ii]=a;
            cost[ii]=c;
            anc[ii][0]=p;
            for(lld i=1;i<LOGN;i++)
                anc[ii][i]=anc[anc[ii][i-1]][i-1];
        }
        else
        {
            lld v,w,ans=0,got=0;
            cin>>v>>w;

            lld tmp=v;
            while(w)
            {
                v=tmp;
                for(lld i=LOGN;i>=0;i--)
                    if(gold[anc[v][i]])
                        v=anc[v][i];
                
                if(gold[v])
                {
                    lld took=min(gold[v],w);
                    debug(v,took,w);

                    ans+=cost[v]*took;
                    got+=took;
                    w-=took;
                    gold[v]-=took;
                }
                else
                    break;
            }

            cout<<got<<" "<<ans<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL); 
    cout.tie(NULL);

    lld tc=1;
    //cin>>tc;

    for(int i=0;i<tc;i++)
    {
        // cout<<"Case #"<<i+1<<": ";
        swagWaalaFunction();
    }
    return 0;
}
