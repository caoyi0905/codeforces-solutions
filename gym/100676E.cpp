#include<bits/stdc++.h>
using namespace std;
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int a[11111];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int i,j,ans=0,n;
        read(n);
        for(i=1;i<=n;i++) read(a[i]);
        sort(a+1,a+n+1);a[n+1]=111111;
        for(i=j=1;i<=n;i++){
            while(a[j]-a[i]<32) j++;
            j--;
            ans+=j-i;
        }
        cout<<ans<<endl;
    }
}
