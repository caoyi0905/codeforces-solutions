#include<bits/stdc++.h>
using namespace std;
int a[111];
int main()
{
    int i,n,ans=0,f=0;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=2;i<n;i++){
        if(a[i-1]==1&&a[i]==0&&a[i+1]==1) a[i]=1;
    }
    for(i=1;i<=n;i++) ans+=a[i];
    cout<<ans<<endl;
}
