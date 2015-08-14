#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,c[61][61];
int main()
{
    int i,j,n,m,t;
    cin>>n>>m>>t;
    c[1][1]=1;
    for(i=2;i<=60;i++){
        c[i][1]=i;
        for(j=2;j<=i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    for(i=4;i<=n;i++){
        int g=t-i;
        if(!g) break;
        ans+=c[n][i]*c[m][g];
    }
    cout<<ans<<endl;
}
