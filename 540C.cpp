#include<bits/stdc++.h>
using namespace std;
char mp[501][501];
int vis[501][501],n,m,r1,c1,r2,c2;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int dfs(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(!vis[xx][yy]) continue;
        if(xx==r2&&yy==c2&&vis[xx][yy]==2){
            cout<<"YES"<<endl;
            exit(0);
        }
        if(vis[xx][yy]==1){
            vis[xx][yy]++;
            dfs(xx,yy);
        }
    }
}
int main()
{
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>mp[i]+1;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            if(mp[i][j]=='X')
                vis[i][j]=2;
            else vis[i][j]=1;
    }
    cin>>r1>>c1>>r2>>c2;
    dfs(r1,c1);
    puts("NO");
}
