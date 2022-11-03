#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mk make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
int dp[502][502];
int a,b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
                dp[i][j]=1e5;
                if(i==j){
                    dp[i][j]=0;
                    continue;
                }
                for(int k=1;k<i;k++){
                    dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
                }
                for(int k=1;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
                }


        }
    }
    cout<<dp[a][b];
}
