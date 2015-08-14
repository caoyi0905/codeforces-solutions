#include<bits/stdc++.h>
#define maxx 100011
using namespace std;
template<typename __ll>
inline void read(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
struct node{int l,c;}a[maxx];
int sum[maxx],f[maxx],h,d,l,g;
bool inline cmp(node a,node b){return a.l<b.l;}
int main()
{
    int i,j,n;
    read(n);
    for(i=1;i<=n;i++) read(a[i].l);
    for(i=1;i<=n;i++) read(a[i].c);
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=n;i++) sum[i]+=sum[i-1]+a[i].c;h=sum[n];
    for(i=1;i<=n;i=j+1){
        for(j=i;a[j+1].l==a[i].l;j++);
        g=sum[n]-sum[j];
        for(l=1,d=2*i-j-1;l<=200&&d>0;l++){
            if(d>f[l]){d-=f[l];g+=f[l]*l;}
            else{g+=d*l;break;}
        }
        h=min(h,g);
        for(l=i;l<=j;l++) f[a[l].c]++;
    }
    printf("%d",h);
}
