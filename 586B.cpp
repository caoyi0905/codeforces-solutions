#include<bits/stdc++.h>
using namespace std;
int a[2][222],b[222];
int sum1[222],sum2[222];
int main()
{
    int i,j,n;
    cin>>n;
    for(i=1;i<=2;i++)
        for(j=2;j<=n;j++)
            cin>>a[i][j];
    for(i=1;i<=n;i++){
        sum1[i]=sum1[i-1]+a[1][i];
    }
    for(i=1;i<=n;i++){
        sum2[i]=sum2[i-1]+a[2][i];
    }
    for(j=1;j<=n;j++) cin>>b[j];
    int ans=100000000;
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        {
            ans=min(ans,b[i]+b[j]+sum1[i]+sum1[j]+sum2[n]-sum2[i]+sum2[n]-sum2[j]);
        }
    cout<<ans<<endl;
}
