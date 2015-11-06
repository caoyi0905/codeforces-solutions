#include<bits/stdc++.h>
using namespace std;
char ch[4][111];
int n,k;
vector<int> v[333];
int vis[4][333];
bool bfs(int x,int y)
{
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        pair<int,int> p=q.front();q.pop();
        if(ch[p.first][p.second+1]!='.') continue;
        for(int i=-1;i<=1;i++)
        {
            int ii=p.first+i,jj=p.second+1;
            if(ii<1||ii>3) continue;
            if(ch[ii][jj]!='.'||ch[ii][jj+1]!='.'||ch[ii][jj+2]!='.'||vis[ii][jj+2]) continue;
            if(jj+2>n) return true;
            vis[ii][jj+2]=1;
            q.push({ii,jj+2});
        }
    }
    return 0;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        int i,j,x,y;
        memset(vis,0,sizeof vis);
        memset(ch,'.',sizeof ch);
        for(i=0;i<=3*n;i++) v[i].clear();
        for(i=1;i<=3;i++)
            for(j=1;j<=n;j++){
                cin>>ch[i][j];
                if(ch[i][j]=='s') x=i,y=j,ch[i][j]='.';
            }
        puts(bfs(x,y)?"YES":"NO");
    }
}
