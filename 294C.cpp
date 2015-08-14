#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int a[1111];
ll f[1111]={1};
template<typename __ll>
inline void read(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
ll pow_mod(ll a,ll b,ll M) {ll res=1;a%=M;for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res;}
int main()
{
    int i,n,m,x,cnt=0,sum=0;ll ans;
    cin>>n>>m;
    for(i=1;i<=n;i++) f[i]=f[i-1]*i%mod;
    for(i=1;i<=m;i++) read(x),a[x]=1;
    vector<int> s;a[n+1]=1;
    for(i=1;i<=n+1;i++){
        if(a[i]==1&&cnt){s.push_back(cnt);sum+=cnt;cnt=0;}
        else if(a[i]==0) cnt++;
    }
    ans=f[sum];
    for(auto i:s){
        ans=ans*pow_mod(f[i],mod-2,mod)%mod;
    }
    for(i=a[1]==0?1:0;i<s.size()-(a[n]==0?1:0);i++){
        ans=ans*pow_mod(2,s[i]-1,mod)%mod;
    }
    cout<<ans<<endl;
}
