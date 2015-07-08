#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,ans=0;
    string a,b;
    cin>>n>>a>>b;
    for(i=0;i<n;i++){
        int x=a[i]-'0';
        int y=b[i]-'0';
        ans+=min(min(abs(x-y),abs(x-y+10)),abs(x-y-10));
    }
    cout<<ans<<endl;
}
