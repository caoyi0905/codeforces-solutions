#include<bits/stdc++.h>
using namespace std;
int c[20];
int main()
{
    int i,j,n,l,r,x,ans=0;
    cin>>n>>l>>r>>x;
    for(i=0;i<n;i++) cin>>c[i];
    for(i=0;i<(1<<n);i++){
        int sum=0,cnt=0,mi=10000000,ma=-1;
        for(j=0;j<n;j++){
            if(1&(i>>j)) sum+=c[j],mi=min(mi,c[j]),ma=max(ma,c[j]);
            cnt++;
        }
        if(cnt>=2&&l<=sum&&sum<=r&&ma-mi>=x) ans++;
    }
    cout<<ans<<endl;
}
