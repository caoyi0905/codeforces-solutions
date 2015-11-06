#include<bits/stdc++.h>
using namespace std;
int g[55][55];
int hh[55],vv[55];
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int main()
{
    int n,v,h,i;
    vector<int> ans;
    cin>>n;
    for(i=1;i<=n*n;i++){
        R(h);R(v);
        if(hh[h]||vv[v]) continue;
        ans.push_back(i);
        g[h][v]=1;
        hh[h]=1;vv[v]=1;
    }
    for(auto i:ans) cout<<i<<' ';
}
