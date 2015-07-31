#include<bits/stdc++.h>
using namespace std;
int a[111];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int i,n,mm=0,ans=0;
        cin>>n;
        for(i=1;i<=n;i++){
            cin>>a[i];
            mm=max(mm,a[i]);
        }
        mm=100-mm;
        for(i=1;i<=n;i++) if(a[i]+mm>=50) ans++;
        printf("%d\n",ans);
    }
}
