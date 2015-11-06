#include<bits/stdc++.h>
using namespace std;
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int a[511*511];
map<int,int> mp;
int main()
{
    int i,j,n;
    vector<int> ans;
    R(n);
    for(i=1;i<=n*n;i++) R(a[i]),mp[a[i]]++;
    while(n--){
        pair<int,int> pp=*(mp.rbegin());
        mp[pp.first]--;if(mp[pp.first]==0) mp.erase(pp.first);
        for(int i=0;i<ans.size();i++){
            int t=__gcd(pp.first,ans[i]);
            mp[t]-=2;
            if(mp[t]==0) mp.erase(t);
        }
        ans.push_back(pp.first);
    }
    for(auto i:ans) cout<<i<<' ';
}
