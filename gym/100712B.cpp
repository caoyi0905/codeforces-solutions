#include<bits/stdc++.h>
using namespace std;
int a[1111][3][2];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int i,j,n,ans=0;
        memset(a,0,sizeof a);
        char ch;
        cin>>n;
        for(i=1;i<=n;i++){
            cin>>ch;
            a[i][0][0]=a[i-1][0][0]+(ch=='S');
            a[i][0][1]=a[i-1][0][1]+(ch=='P');
            a[i][1][0]=a[i-1][1][0]+(ch=='R');
            a[i][1][1]=a[i-1][1][1]+(ch=='S');
            a[i][2][0]=a[i-1][2][0]+(ch=='P');
            a[i][2][1]=a[i-1][2][1]+(ch=='R');
        }
        for(i=0;i<=n;i++){
            for(j=i;j<=n;j++){
                if(a[i][0][0]+a[j][1][0]-a[i][1][0]+a[n][2][0]-a[j][2][0]>
                   a[i][0][1]+a[j][1][1]-a[i][1][1]+a[n][2][1]-a[j][2][1]) ans++;
            }
        }
        cout<<ans<<endl;
    }
}
