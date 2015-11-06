#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll> Fib;
ll n,k,l,m,res=1;
ll f(ll x)
{
    if(Fib.count(x)) return Fib[x];
    return Fib[x]=(f((x+1)/2)*f(x/2)+f((x-1)/2)*f((x-2)/2))%m;
}
ll pow_mod(ll a,ll b,ll M) {ll res=1;a%=M;for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res;}
int main()
{
    cin>>n>>k>>l>>m;Fib[0]=Fib[1]=1;
    for(ll i=0;i<l;i++){
        if(k&(1LL<<i)) res=res*(pow_mod(2,n,m)-f(n+1)+m)%m;
        else res=res*f(n+1)%m;
        while(res<0) res+=m;
    }
    for(ll i=l;i<60;i++) if(k&(1LL<<i)) res=0,i=61;
    cout<<res%m;
}
