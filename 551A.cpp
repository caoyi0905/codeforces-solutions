#include<bits/stdc++.h>
using namespace std;
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
set<int> s;
vector<int> v[2011];
int ans[2011];
int main()
{
    int i,n,x;
    R(n);
    for(i=1;i<=n;i++){
        R(x);
        v[x].push_back(i);
        s.insert(-x);
    }
    int pos=1;
    for(auto it:s){
        x=-it;
        for(i=0;i<v[x].size();i++){
            ans[v[x][i]]=pos;
        }
        pos+=v[x].size();
    }
    for(i=1;i<=n;i++) printf("%d ",ans[i]);
}
