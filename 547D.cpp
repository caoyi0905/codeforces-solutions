#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=201111;
vector<int> v[N];
int t[N],a[N][2];
void dfs(int x,int y){
    if(t[x]) return ;
    t[x]=y;
    for(int i=0;i<v[x].size();i++) dfs(v[x][i],3-y);
}
int main()
{
    int i,j,n,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=0;j<2;j++){
            scanf("%d",&x);
            if(a[x][j]){
                v[i].pb(a[x][j]);
                v[a[x][j]].pb(i);
                a[x][j]=0;
            }else a[x][j]=i;
        }
    }
    for(i=1;i<=n;i++) dfs(i,1),putchar(t[i]>1?'r':'b');
}
