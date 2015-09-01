#include<bits/stdc++.h>
using namespace std;
template<typename __ll>
inline void read(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
vector<int>g[4444];
bool vis[4111][4111];
int main()
{
    int i,j,k,n,m,a,b,c,ans=0x3f3f3f3f;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        int x,y;
        read(x);read(y);vis[x][y]=vis[y][x]=1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i=1;i<=n;i++){
        a=i;
        for(j=0;j<g[i].size();j++){
            b=g[i][j];
            for(k=0;k<g[b].size();k++){
                c=g[b][k];
                if(vis[a][c]){
                    ans=min(ans,int(g[a].size()+g[b].size()+g[c].size()-6));
                }
            }
        }
    }
    if(ans==0x3f3f3f3f) puts("-1");
    else printf("%d",ans);
}
