#include<bits/stdc++.h>
using namespace std;
int dp[501][501];
int main()
{
    int i,j,k,n,m,b,mod,a;
    cin>>n>>m>>b>>mod;
    for(i=0;i<=500;i++) dp[0][i]=1;
    for(i=1;i<=n;i++){
        cin>>a;
        for(j=1;j<=500;j++){
            for(k=a;k<=500;k++){
                dp[j][k]=(dp[j][k]+dp[j-1][k-a])%mod;
            }
        }
    }
    cout<<dp[m][b];
}
