#include<bits/stdc++.h>
#define mod 1000000007
#define N 2002
using namespace std;
long long dp[N][N];
int main()
{
    int i,j,n,m;
    string s;
    cin>>n>>m>>s;
    dp[0][0]=1;
    for(i=1;i<=n-m;i++){
        for(j=0;j<=i;j++){
            if(!j) dp[i][j]=dp[i-1][j+1];
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
        }
    }
    int cnt=0,d=m+1;
    for(i=0;i<m;i++){
        if(s[i]=='(') cnt++;
        else cnt--;
        d=min(d,cnt);
    }
    long long ans=0;
    for(i=0;i<=n-m;i++){
        for(j=0;j<=i;j++){
            if(d+j>=0&&cnt+j<=n-m-i)
                ans=(ans+dp[i][j]*dp[n-m-i][cnt+j])%mod;
        }
    }
    cout<<ans;
}
