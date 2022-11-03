#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mk make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
int dp[100][100010];
int n;
int x[100];
unordered_set<int> s;
void go(int cr,int sum){
    if(cr>=n){
        if(sum>0)
        s.insert(sum);
        return;
    }
    int &ret=dp[cr][sum];
    if(ret!=-1)return;
    ret=0;
    go(cr+1,sum);
    go(cr+1,sum+x[cr]);
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)cin>>x[i];
    memset(dp,-1,sizeof dp);
    go(0,0);
    vector<int> v;
    cout<<s.size()<<endl;
    for(int element: s){
        v.pb(element);
        //cout<<element<<endl;
    }
    sort(v.begin(),v.end());
    for(int element: v){
        cout<<element<<' ';
    }
}
