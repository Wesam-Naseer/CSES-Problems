#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mk make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
ll dp[1000100][2][2];
ll mod=1e9+7;
ll n;
ll go(int cr,int g,int g2){
    if(cr<=0)return 1;
    ll &ret=dp[cr][g][g2];
    if(ret!=-1)return ret;
    ret=0;
    ret+=go(cr-1,0,1);
    if(g==0&&g2!=0)
    ret+=go(cr-1,0,1)*3;
    if(g==1){
        ret+=go(cr-1,1,1);
    }
    ret+=go(cr-1,1,1);
    ret%=mod;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    memset(dp,-1,sizeof dp);
    while(t--){

        cin>>n;
        cout<<go(n,0,0)<<endl;
    }
}
