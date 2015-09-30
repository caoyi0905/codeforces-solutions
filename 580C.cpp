#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int a[111111];
vector<int> v[111111];
int ans=0,m;
void dfs(int root,int x,int last){
    int cnt=0;
    for(int i=0;i<v[root].size();i++){
        int u=v[root][i];
        if(u==last) continue;cnt++;
        if(a[u]==1&&x<m) dfs(u,x+1,root);
        else if(a[u]==0) dfs(u,0,root);
    }
    if(!cnt) ans++;
}
int main()
{
    int i,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,a[1],0);
    cout<<ans;
}
