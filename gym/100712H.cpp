#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=100005;
const int MAXM=200005;
struct Edge
{
    int to,next;
    bool cut;
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,top;
int block;
bool Instack[MAXN];
int bridge;
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].cut=0;
    head[u]=tot++;
}
void Tarjan(int u,int pre)
{
    int v;
    Low[u]=DFN[u]=++Index;
    Stack[top++]=u;
    Instack[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].to;
        if(v==pre)continue;
        if(!DFN[v])
        {
            Tarjan(v,u);
            if(Low[u]>Low[v])Low[u]=Low[v];
            if(Low[v]>DFN[u])
            {
                bridge++;
                edge[i].cut=1;
                edge[i^1].cut=1;
            }
        }
        else if(Instack[v] && Low[u]>DFN[v])
            Low[u]=DFN[v];
    }
    if(Low[u]==DFN[u])
    {
        block++;
        do
        {
            v=Stack[--top];
            Instack[v]=0;
            Belong[v]=block;
        }
        while(v!=u);
    }
}
vector<int>e[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)e[i].clear();
    tot=0;
    memset(head,-1,sizeof(head));
}
int dis[MAXN];
void bfs(int st)
{
    queue<int>q;
    q.push(st);
    dis[st]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<e[u].size();i++)
        {
            if(dis[e[u][i]]>dis[u]+1)
            {
                q.push(e[u][i]);
                dis[e[u][i]]=dis[u]+1;
            }
        }
    }
}
void solve(int n)
{
    memset(DFN,0,sizeof(DFN));
    memset(Instack,0,sizeof(Instack));
    Index=top=block=bridge=0;
    Tarjan(1,0);
    for(int i=1;i<=n;i++)
        for(int j=head[i];j!=-1;j=edge[j].next)
            if(edge[j].cut)
            {
                e[Belong[edge[j].to]].push_back(Belong[i]);
                e[Belong[i]].push_back(Belong[edge[j].to]);
            }
    memset(dis,0x3f3f3f3f,sizeof(dis));
    bfs(1);
    int ans=0,loc=1;
    for(int i=1;i<=block;i++)
    {
        if(dis[i]>ans)
        {
            loc=i;
            ans=dis[i];
        }
    }
    memset(dis,0x3f3f3f3f,sizeof(dis));
    bfs(loc);
    ans=0;
    for(int i=1;i<=block;i++)ans=max(ans,dis[i]);
    printf("%d\n",bridge-ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        init(n);
        int u,v;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        solve(n);
    }
    return 0;
}
