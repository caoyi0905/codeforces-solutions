#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int n,m,k,a[111111];
ll l,r,mid;
int check(ll x)
{
    ll sum=0;
    int tmp=m;
    for(int i=1;i<=k;i++){
        sum+=a[i];
        while(sum>=x-i){
            sum-=x-i;
            tmp--;
            if(tmp<0) return 0;
        }
    }
    if(tmp==0&&sum>0) return 0;
    return 1;
}
int main()
{
    int i;
    R(n);R(m);
    for(i=1;i<=n;i++){
        R(a[i]);
        if(a[i]>0) k=i;
    }
    l=k;r=1LL<<62;
    while(l<r){
        mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l;
}
