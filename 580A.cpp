#include<bits/stdc++.h>
using namespace std;
int a[111111];
template<typename __ll>
inline void read(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++) read(a[i]);
    int maxx=0,cnt=1;
    i=2;
    a[n+1]=-1;
    while(i<=n+1){
        if(a[i]>=a[i-1])
            cnt++;
        else{
            maxx=max(maxx,cnt);
            cnt=1;
        }
        i++;
    }
    cout<<max(maxx,cnt);
}
