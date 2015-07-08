#include<bits/stdc++.h>
#define N 500111
using namespace std;
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int n,q,x,a[N],cnt[N],mu[N],v[N],vis[N];
vector<int> b[N];
long long ans;
int main()
{
    int i,j;
    read(n);read(q);
    for(i=1;i<=n;i++) read(a[i]),v[a[i]]=1;
    mu[1]=1;
    for(i=1;i<=500000;i++){
        for(j=i;j<=500000;j+=i){
            if(v[j]) b[j].push_back(i);
            if(j!=i) mu[j]-=mu[i];
        }
    }
    for(i=1;i<=q;i++){
        read(x);
        if(!vis[x]){
            vis[x]=1;
            for(int p:b[a[x]]) ans+=mu[p]*(cnt[p]++);
        }else{
            vis[x]=0;
            for(int p:b[a[x]]) ans-=mu[p]*(--cnt[p]);
        }
        printf("%I64d\n",ans);
    }
}
