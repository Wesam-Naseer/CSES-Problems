#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mk make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
const ll mod=1e9+7;
ll dp[501][500*502/2];
int n;
int mx;
ll go(int cr,int sm){
    if(sm<0||sm>mx)return 0;
    if(cr>n){
        if(sm==mx/2){return 1;}
        return 0;
    }
    ll &ret=dp[cr][sm];
    if(ret!=-1)return ret;
    ret=0;
    ret+=go(cr+1,sm-cr);
    ret+=go(cr+1,sm+cr);
    if(ret>=mod)ret-=mod;
    return ret;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof dp);
    cin>>n;
    mx=n*(n+1)/2;
    ll ans=go(1,mx/2);
    if(ans%2)ans+=mod;
    ans/=2;
    cout<<ans<<endl;
}
