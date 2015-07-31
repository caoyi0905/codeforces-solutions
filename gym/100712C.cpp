#include<bits/stdc++.h>
using namespace std;
int a[111];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int i,n,ans=0;string str;
        cin>>n>>str;
        memset(a,0,sizeof a);
        for(i=0;i<n;i++){
            if(str[i]=='*'){
                if(i>0) a[i-1]=1;
                a[i]=a[i+1]=1;
            }
        }
        a[n]=1;
        int s=0;
        for(i=0;i<=n;i++){
            if(a[i]==1){
                ans+=s/3+(s%3!=0);
                s=0;
            }else s++;
        }
        cout<<ans<<endl;
    }
}
