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
int a[3];
int main()
{
    int i,n,k,x;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        read(x);
        a[x%2]++;
    }
    if((n-k)%2==0){
        if(a[0]<)
    }
}
