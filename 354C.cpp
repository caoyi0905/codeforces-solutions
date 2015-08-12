#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
    int i,n,m,k,mi=9999999;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a[i];
        mi=min(mi,a[i]);
    }
    sort(a+1,a+n+1);
    if(k>=mi) cout<<mi<<endl;
    else{
        int x=mi;
        while(1){
            for(i=1;i<=n;i++){
                if(a[i]%x>k){
                    x=a[i]/(a[i]/x+1);
                    break;
                }
            }
            if(i==n+1){printf("%d",x);break;}
        }
    }
}
