#include<bits/stdc++.h>
#define maxx 1000011
#define ll long long
#define mod 1000000007
using namespace std;
ll fac[maxx],inv[maxx];
ll mul(ll x,ll y,ll z){return (x*y-(ll)(x/(long double)z*y+1e-3)*z+z)%z;}
ll pow_mod(ll a,ll b,ll M) {ll res=1;a%=M;for(;b;b>>=1){if(b&1)res=mul(res,a,M);a=mul(a,a,M);}return res;}
ll C(ll n,ll k){
    return fac[n]*inv[k]%mod*inv[n-k]%mod;
}
void init(int n)
{
    int i;fac[0]=inv[0]=1;
    for(i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%mod;
    for(i=n-1;i>0;i--){
        inv[i]=pow_mod(fac[i],mod-2,mod);
    }
}
ll a[1005];
int main()
{
    int i,n;
    cin>>n;
    ll ans=1,sum=0;
    for(i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    init(sum);
    for(i=n;i>=1;i--){
        ans=ans*C(sum-1,a[i]-1)%mod;
        sum-=a[i];
    }
    cout<<ans<<endl;
}
