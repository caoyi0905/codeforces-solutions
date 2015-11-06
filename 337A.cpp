#include<bits/stdc++.h>
using namespace std;
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int f[51];
int main()
{
    int i,n,m,ans=0x3f3f3f3f;
    R(n);R(m);
    for(i=1;i<=m;i++) R(f[i]);
    sort(f+1,f+m+1);
    for(i=1;i+n-1<=m;i++)
        ans=min(ans,f[i+n-1]-f[i]);
    cout<<ans<<endl;
}
