#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100001];
map<ll,ll> mp;
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int main()
{
    ll i,n,ans1,ans2,tt=0;
    ll k;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        R(a[i]);
        mp[a[i]]++;
    }
    sort(a+1,a+n+1);
    for(auto it:mp){
        tt++;
        if(it.second*n>=k){
            ans1=it.first;
            ans2=a[(k-1)/it.second+1];
            cout<<ans1<<' '<<ans2<<endl;
            return 0;
        }else k-=it.second*n;
    }
}
