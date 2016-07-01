#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> g[1111111];
bool col[1111111];
bool vis[1234567];
int cnt=0;
void dfs(int u){
    vis[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]){
            if(col[v]==col[u]){
                puts("-1");
                exit(0);
            }
        }
        else{
            col[v]=1^col[u];
            cnt+=col[v];
            dfs(v);
        }
    }
    return ;
}
int main()
{
    int u,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        if(u==v) continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])
            dfs(i);
    }
    printf("%d\n",cnt);
    for(int i=1;i<=n;i++)
        if(col[i])printf("%d ",i);
    printf("\n%d\n",n-cnt);
    for(int i=1;i<=n;i++)
        if(!col[i])printf("%d ",i);
}
