#include<bits/stdc++.h>
using namespace std;
int dp[4444];
int main()
{
    int a,b,c,i,n;
    cin>>n>>a>>b>>c;
    fill(dp+1,dp+4444,-1e9);
    for(i=1;i<=n;i++){
        if(i>=a) dp[i]=max(dp[i],dp[i-a]+1);
        if(i>=b) dp[i]=max(dp[i],dp[i-b]+1);
        if(i>=c) dp[i]=max(dp[i],dp[i-c]+1);
    }
    printf("%d",dp[n]);
}
