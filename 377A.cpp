#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char ch[501][501];
int vis[501][501];
void dfs(int x,int y)
{
    if(x<1||x>n||y<1||y>m||ch[x][y]!='.'||vis[x][y]) return ;
    vis[x][y]=1;
    dfs(x+1,y);dfs(x-1,y);
    dfs(x,y+1);dfs(x,y-1);
    if(k) ch[x][y]='X',k--;
}
int main()
{
    int i,j;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
        cin>>ch[i]+1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(ch[i][j]=='.'&&k) dfs(i,j);
    for(i=1;i<=n;i++) puts(ch[i]+1);
}
