#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll,int>
#define inf LONG_LONG_MAX/3
#define ll long long
using namespace std;
int n,m,cnt,last[1000011];
int x,y,z;
ll dis[1000005];
struct data{int to,next,id;ll v;}e[1000011];
inline void read(int &m){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
void add(int u,int v,int w,int i){
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;e[cnt].id=i;
}
priority_queue<pp,vector<pp>,greater<pp> > q;
void dijkstra(int s){
    for(int i=1;i<=n;i++) dis[i]=inf;
    dis[s]=0;q.push(make_pair(0,s));
    while(!q.empty())
    {
        int now=q.top().second;q.pop();
        for(int i=last[now];i;i=e[i].next){
            ll d=e[i].v+dis[now];
            if(dis[e[i].to]>d){
                dis[e[i].to]=d;
                q.push(make_pair(dis[e[i].to],e[i].to));
            }
        }
    }
}
vector<int> ans;
ll sum;
void Out(int a)
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
int main()
{
    int i,u,v,w;
    read(n);read(m);
    for(i=1;i<=m;i++){
        read(u);read(v);read(w);
        add(u,v,w,i);add(v,u,w,i);
    }
    read(u);
    dijkstra(u);
    for(v=1;v<=n;v++){
        if(v==u) continue;
        ll Mi=LONG_LONG_MAX,id;
        for(int i=last[v];i;i=e[i].next){
            int now=e[i].to;
            if(dis[v]==dis[now]+e[i].v&&Mi>e[i].v){
                Mi=e[i].v;
                id=e[i].id;
            }
        }
        sum+=Mi;
        ans.push_back(id);
    }
    printf("%I64d\n",sum);
    for(int i=0;i<ans.size();i++)
        Out(ans[i]),putchar(' ');
}
