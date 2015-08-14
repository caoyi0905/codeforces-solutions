#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char c[111][111];
int cnt[111];
int main()
{
    int i,j,n,m;long long ans=1;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>c[i]+1;
    for(i=1;i<=m;i++){
        set<char> s;
        for(j=1;j<=n;j++)
            s.insert(c[j][i]);
        ans=ans*s.size()%mod;
    }
    cout<<ans<<endl;
}
