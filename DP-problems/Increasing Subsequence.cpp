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
int seg[200100*4];
int n;
int x[200100];
int l,r,ls;
int get(int cr,int s,int e){
    if(s>r||l>e)return 0;
    if(l<=s&&e<=r){return seg[cr];}
    return max(get(cr*2,s,(s+e)/2),get(cr*2+1,(s+e)/2+1,e));
}
void upd(int cr,int s,int e){
    if(s>l||e<l)return;
    if(s==e){
        seg[cr]=ls;
        return;
    }
    upd(cr*2,s,(s+e)/2);
    upd(cr*2+1,(s+e)/2+1,e);
    seg[cr]=max(seg[cr*2],seg[cr*2+1]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        v.pb(x[i]);
    }
    sort(v.begin(),v.end());
    unordered_map<int,int> m;
    int cr=1;
    for(int i=0;i<n;i++){
        if(i>0&&v[i]==v[i-1])continue;
        m[v[i]]=cr;
        cr++;
    }
    for(int i=1;i<=n;i++){
        x[i]=m[x[i]];
    }
    int ans=0;
    for(int i=n;i>=1;i--){
        l=x[i]+1;r=n;
        ls=get(1,1,n)+1;
        l=x[i];
        ans=max(ans,ls);
        upd(1,1,n);
    }
    cout<<ans<<endl;

}
