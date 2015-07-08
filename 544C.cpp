#include<bits/stdc++.h>
using namespace std;
int a[511];
long long dp[2][501][501];
int main()
{
    int i,j,k,p,n,m,b;long long mod;
    cin>>n>>m>>b>>mod;
    for(i=1;i<=n;i++) cin>>a[i];
    ///枚举现在是第i个在搞 然后第j行 然后已有的bug为k的方案
    dp[0][0][0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<=m;j++){
            for(p=0;p<=j;p++){
                for(k=p*a[i];k<=b;k++){
                    dp[i&1][j][k]=(dp[(i)&1][j][k]+dp[(i-1)&1][j-p][k-p*a[i]])%mod;
                    cout<<i<<' '<<j<<' '<<k<<' '<<dp[i&1][j][k]<<endl;
                }
            }
        }
    }
    long long ans=0;
    for(i=0;i<=b;i++) ans=(ans+dp[n&1][m][i])%mod;
    cout<<ans<<endl;
}
