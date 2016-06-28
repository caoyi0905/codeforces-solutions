#include<bits/stdc++.h>
using namespace std;
const int maxx=3e5+10;
int n,m,cnt;
int ans[maxx],f[maxx],siz[maxx];
int head[maxx];
struct Edge{int next,to;}edge[maxx];
void add(int u,int v){edge[cnt].to=v;edge[cnt].next=head[u];head[u]=cnt++;}
void dfs(int u){
    siz[u]=1;
    ans[u]=u;
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        dfs(v);
        siz[u]+=siz[v];
    }
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(siz[v]*2>siz[u]){
            ans[u]=ans[v];
            break;
        }
    }
    while((siz[u]-siz[ans[u]])*2 > siz[u]) ans[u]=f[ans[u]];
}
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int main()
{
    read(n);read(m);
    memset(head,-1,sizeof head);
    for(int i=2;i<=n;i++){
        read(f[i]);
        add(f[i],i);
    }
    dfs(1);
    int v;
    while(m--){
        read(v);
        printf("%d\n",ans[v]);
    }
}
