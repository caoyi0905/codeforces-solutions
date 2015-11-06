#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll pow_mod(ll a,ll b,ll M) {ll res=1;a%=M;for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res;}
int main()
{
    ll n;
    cin>>n;
    cout<<(pow_mod(27,n,mod)-pow_mod(7,n,mod)+mod)%mod<<endl;
}
