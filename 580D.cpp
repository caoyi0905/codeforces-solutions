#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int a[19];
long long dp[262150][19],n,m,k;
int tt[20][20];
int main()
{
    int i;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=k;i++){
        int x,y,c;
        cin>>x>>y>>c;
        tt[x][y]=c;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        dp[(1<<(i-1))][i]=a[n-i+1];
        ans=max(ans,dp[(1<<(i-1))][i]);
    }
    for(i=0;i<(1<<n);i++){
        if(__builtin_popcount(i)>=m) continue;
        for(int j=1;j<=n;j++)if((i>>j-1)&1){
            for(int k=1;k<=n;k++){
                if(k==j||(i>>k-1)&1) continue;
                int t=i|(1<<(k-1));
                dp[t][k]=max(dp[t][k],dp[i][j]+tt[n-j+1][n-k+1]+a[n-k+1]);
                if(__builtin_popcount(t)==m)
                    ans=max(ans,dp[t][k]);
            }
        }
    }
    cout<<ans;
}
