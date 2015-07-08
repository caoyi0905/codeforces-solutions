#include<bits/stdc++.h>
using namespace std;
char mp[111][111];
int n,k;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int isok(int x,int y,int p,int q){
    if(mp[p][q]=='L') return 0;
    for(int i=0;i<4;i++){
        int ii=p+dx[i];
        int jj=q+dy[i];
        if(ii<1||ii>n||jj<1||jj>n||(ii==x&&jj==y)) continue;
        if(mp[ii][jj]=='L') return 0;
    }
    return 1;
}
void bfs(int x,int y){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        pair<int,int> p=q.front();q.pop();
        for(int i=0;i<4;i++){
            int ii=p.first+dx[i];
            int jj=p.second+dy[i];
            if(ii<1||ii>n||jj<1||jj>n||mp[ii][jj]=='L') continue;
            if(isok(x,y,ii,jj)){
                mp[ii][jj]='L';
                q.push(make_pair(ii,jj));
            }
        }
    }
}
int main()
{
    int i,j,cnt=0;
    cin>>n>>k;
    if(k>(n*n+1)/2){return puts("NO");}
    puts("YES");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            mp[i][j]='S';
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(cnt<k&&(i+j)%2==0){
                mp[i][j]='L';
                cnt++;
            }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(mp[i][j]=='L')
                bfs(i,j);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            cout<<mp[i][j];
        cout<<endl;
    }
}
