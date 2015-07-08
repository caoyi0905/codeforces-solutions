#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main()
{
    int i,j,n,k,m,ans=0,a;
    cin>>n>>k;
    for(i=1;i<=k;i++){
        cin>>m;
        for(j=1;j<=m;j++){
            cin>>a;
            mp[a]=i;
        }
        ans+=m-1;
    }
    for(i=1;i<n;i++)
        if(mp[i]!=mp[i+1]){
            break;
        }
    i--;
    ans=ans+n-1-2*i;
    cout<<ans;
}
