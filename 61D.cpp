#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int,int> > v[100001];
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int n;
ll tot;
int dfs(int a,int b){
    int ans=0;
    for(int i=0;i<v[a].size();i++){
        if(v[a][i].first==b) continue;
        ans=max(ans,v[a][i].second+dfs(v[a][i].first,a));
    }
    return ans;
}
int main()
{
    int i,a,b,c;
    read(n);
    for(i=1;i<n;i++){
        read(a);read(b);read(c);
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
        tot+=c;
    }
    cout<<2*tot-dfs(1,0)<<endl;
}
