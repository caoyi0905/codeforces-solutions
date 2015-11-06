#include<bits/stdc++.h>
using namespace std;
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int a[150001];
int main()
{
    int i,n,m;
    R(n);R(m);
    for(i=1;i<=n;i++) R(a[i]);
    int sum=0,idx=1,ans=0;
    for(i=1;i<=m;i++) sum+=a[i];
    ans=sum;
    for(i=m+1;i<=n;i++){
        sum+=a[i]-a[i-m];
        if(ans>sum){
            ans=sum;
            idx=i-m+1;
        }
    }
    cout<<idx<<endl;
}
