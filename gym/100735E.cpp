#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[101][101];
template<typename __ll>
inline void read(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
ll tot;
int main()
{
    int i,j;ll n,sum;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            read(a[i][j]);tot+=a[i][j];
        }
    sum=tot/(n-1);
    for(i=1;i<=n;i++)
    {
        ll s=0;
        for(j=1;j<=n;j++) s+=a[i][j];
        a[i][i]=sum-s;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            printf("%I64d%c",a[i][j],j==n?'\n':' ');

}
