#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mk make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
ll dp[5001][5001];
ll sum[5001];
int n;
ll x[5001];
ll go(int l,int r){
    if(l>r)return 0;
    ll &ret=dp[l][r];
    if(ret!=-1)return ret;
    ret=-1e16;
    ret=max(ret,go(l+1,r)+x[l]);
    ret=max(ret,go(l,r-1)+x[r]);
    ret=sum[r]-sum[l-1]-ret;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        sum[i]=sum[i-1]+x[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<max(go(2,n)+x[1],go(1,n-1)+x[n]);
}
