#include<bits/stdc++.h>
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
template<typename __ll>
inline void read(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int main()
{
    int i,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++) read(a[i]);
    for(i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,a[1],0);
    cout<<ans;
}
