#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mk make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
ll dp[200100];
vector<tuple<ll,ll,ll> > v;
vector<tuple<ll,ll,ll> >:: iterator it;

int n;
ll go(int project){
    if(project>=n){return 0;}
    ll &ret=dp[project];
    if(ret!=-1)return ret;
    ret=0;
    ret=max(ret,go(project+1));
    tuple<ll,ll,ll> tu={get<1>(v[project])+1,0,0};
    it=lower_bound(v.begin(),v.end(),tu);
    if(it!=v.end())
        ret=max(ret,go(it-v.begin())+get<2>(v[project]));
    else{
        ret=max(ret,get<2>(v[project]));
    }

    return ret;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++){
        ll a,b,p;
        cin>>a>>b>>p;
        v.pb({a,b,p});
    }
    sort(v.begin(),v.end());
    cout<<go(0);

}
