#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define eps 1e-10
typedef double F;
#define F_INF (1e20)
#define MAXV 10000
#define MAXE 80*10000// E*2!
F cap[MAXE],flow[MAXE];
int to[MAXE],_prev[MAXE],last[MAXV],used[MAXV],level[MAXV];
struct MaxFlow{
    int V,E;
    MaxFlow(int n){
        int i;
        V=n;E=0;
        REP(i,V) last[i]=-1;
    }
    void add_edge(int x,int y,F f){
        cap[E]=f;flow[E]=0;to[E]=y;_prev[E]=last[x];last[x]=E;E++;
        cap[E]=0;flow[E]=0;to[E]=x;_prev[E]=last[y];last[y]=E;E++;
    }
    bool bfs(int s,int t){
        int i;
        REP(i,V) level[i]=-1;
        queue<int> q;
        q.push(s);level[s]=0;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(i=last[x];i>=0;i=_prev[i]) if(level[to[i]]==-1&&cap[i]>flow[i]) {q.push(to[i]);level[to[i]]=level[x] + 1;}
        }
        return (level[t]!=-1);
    }
    F dfs(int v,int t,F f){
        int i;
        if(v==t) return f;
        for(i=used[v];i>=0;used[v]=i=_prev[i]) if(level[to[i]]>level[v]&&cap[i]>flow[i]){
            F tmp=dfs(to[i],t,min(f,cap[i]-flow[i]));
            if(tmp>0) {flow[i]+=tmp;flow[i^1]-=tmp;return tmp;}
        }
        return 0;
    }
    F maxflow(int s,int t){
        int i;
        while(bfs(s,t)){
            REP(i,V) used[i]=last[i];
            while(dfs(s,t,F_INF) !=0);
        }
        F ans=0;
        for(i=last[s];i>=0;i=_prev[i]) ans+=flow[i];
        return ans;
    }
};
int n,m;
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
struct edg{
    int u,v;
}E[MAXE];
bool check(double k){
    int i;
    MaxFlow f(m+n+2);
    for(i=1;i<=n;i++) f.add_edge(i,m+n+1,k);
    for(i=1;i<=m;i++) f.add_edge(n+i,E[i].u,F_INF),f.add_edge(n+i,E[i].v,F_INF),f.add_edge(0,n+i,1);
    double ans=m-f.maxflow(0,m+n+1);
    return ans<eps;
}
int a[111];
int main()
{
    int i,j,u,v,T,cas=1;
    cin>>T;
    while(T--){
        cin>>n;
        m=0;
        for(i=1;i<=n;i++) read(a[i]);
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                if(a[i]>a[j])
                    E[++m].u=i,E[m].v=j;
        double l=0,r=m,mid;
        while(l+eps<=r){
            mid=(l+r)/2;
            if(check(mid)) r=mid;
            else l=mid;
        }
        printf("Case #%d: %.10lf\n",cas++,l);
    }
}
