#include<bits/stdc++.h>
using namespace std;
int a[16],ans,n,tot;
bool vis[16];
struct node{
    int a,b,c;
};
vector<node> vt;
bool check(int x,int y,int z){
    if(x+y>z&&y+z>x&&x+z>y) return 1;
    return 0;
}
void dfs(int x,int cnt){
    ans=max(ans,cnt);
    for(int i=x+1;i<tot;i++){
        node t=vt[i];
        if(vis[t.a]||vis[t.b]||vis[t.c]) continue;
        vis[t.a]=vis[t.b]=vis[t.c]=1;
        dfs(i,cnt+1);
        vis[t.a]=vis[t.b]=vis[t.c]=0;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(check(a[i],a[j],a[k])) vt.push_back({i,j,k});
            }
        }
    }
    tot=vt.size();
    dfs(-1,0);
    cout<<ans;
}
