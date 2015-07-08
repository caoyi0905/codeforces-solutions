#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#define ll long long
#define pa pair<ll,int>
#define llinf 9000000000000000000LL
using namespace std;
using namespace __gnu_pbds;
typedef __gnu_pbds::priority_queue<pa,greater<pa>,pairing_heap_tag > heap;
int n,m,cnt,last[1000011];
int T,rxa,rxc,rya,ryc,rp;
heap::point_iterator id[1000011];
int x,y,z;
ll dis[1000011];
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
void dijkstra(int u){
    heap q;
    for(int i=1;i<=n;i++)dis[i]=llinf;
    dis[u]=0;id[u]=q.push(make_pair(0,u));
    while(!q.empty()){
        int now=q.top().second;q.pop();
        for(int i=last[now];i;i=e[i].next)
            if(e[i].v+dis[now]<dis[e[i].to]){
                dis[e[i].to]=e[i].v+dis[now];
                if(id[e[i].to]!=0)
                    q.modify(id[e[i].to],make_pair(dis[e[i].to],e[i].to));
                else id[e[i].to]=q.push(make_pair(dis[e[i].to],e[i].to));
            }
    }
}
void Out(int a)
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
vector<int> ans;
ll sum;
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
