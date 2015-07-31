#include<bits/stdc++.h>
using namespace std;
int f[1000001],a[50001];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int i,d,n,num=0,x;
        long long ans=0;
        memset(f,0,sizeof f);
        scanf("%d%d",&d,&n);
        for(i=1;i<=n;i++){
            scanf("%d",a+i);
            a[i]=(a[i]%d+a[i-1])%d;
            if(a[i]==0) ans++;
            ans+=f[a[i]];
            f[a[i]]++;
        }
        cout<<ans<<endl;
    }
}
