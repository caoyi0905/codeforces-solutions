#include<bits/stdc++.h>
#define N 100001
using namespace std;
vector<int> v[N],ans;
int n,c[N];
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
void dfs(int u,int f,int s){
	if(c[u]^(s&1)){
		s^=1;
		ans.push_back(u);
	}
	s=s>>1|(s&1)<<1;
	for(int e:v[u])if(e!=f)
		dfs(e,u,s);
}
int main()
{
    int i,a,b;
    read(n);
    for(i=1;i<n;i++){
        read(a);read(b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1;i<=n;i++) read(c[i]);
    for(i=1;i<=n;i++){
        read(a);
        c[i]^=a;
    }
    dfs(1,0,0);
    printf("%d\n",ans.size());
    for(int i:ans) printf("%d\n",i);
}
