#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
ll ans;
map<int,ll> mp,mp2;
int main()
{
    int i,n,x;ll k;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        read(x);
        if(x%k==0){
            ans+=mp[x/k];
            mp[x]+=mp2[x/k];
        }
        mp2[x]++;
    }
    cout<<ans<<endl;
}
