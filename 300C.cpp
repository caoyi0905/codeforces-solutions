#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll f[1111111]={1};
ll pow_mod(ll a,ll b,ll M) {ll res=1;a%=M;for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res;}
void init(int n){
    for(int i=1;i<=n;i++) f[i]=f[i-1]*i%mod;
}
ll C(ll n,ll k){
    ll x=pow_mod(f[k],mod-2,mod);
    ll y=pow_mod(f[n-k],mod-2,mod);
    return f[n]*x%mod*y%mod;
}
ll ans,a,b,n;
bool check(ll x){
    while(x){
        ll p=x%10;
        if(p!=a&&p!=b) return 0;
        x/=10;
    }
    return 1;
}
int main()
{
    cin>>a>>b>>n;
    init(n);
    for(int i=0;i<=n;i++){
        if(check(a*i+b*(n-i))){
            ans=(ans+C(n,i))%mod;
        }
    }
    cout<<ans<<endl;
}
