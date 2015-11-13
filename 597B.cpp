#include<bits/stdc++.h>
using namespace std;
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int main()
{
    int n,ans=0,last=-1;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) R(v[i].second),R(v[i].first);
    sort(v.begin(),v.end());
    for(auto it:v){
        if(it.second>last){
            last=it.first;
            ans++;
        }
    }
    cout<<ans<<endl;
}
