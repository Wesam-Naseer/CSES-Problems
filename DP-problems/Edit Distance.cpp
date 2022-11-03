#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mk make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
int dp[5001][5001];
int n,m;
string s,t;
int go(int idx1,int idx2){
    if(idx1==n)return m-idx2;
    if(idx2==m)return n-idx1;
    int &ret=dp[idx1][idx2];
    if(ret!=-1)return ret;
    ret=1e9;
    ret=min(ret,go(idx1+1,idx2)+1);// remove
    ret=min(ret,go(idx1,idx2+1)+1);// add
    ret=min(ret,go(idx1+1,idx2+1)+1);// replace
    if(s[idx1]==t[idx2]){
        ret=min(ret,go(idx1+1,idx2+1));
    }
    return ret;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>t;
    n=s.size();
    m=t.size();
    memset(dp,-1,sizeof dp);
    cout<<go(0,0);
}
