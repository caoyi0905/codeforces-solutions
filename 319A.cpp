#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll pow_mod(ll a,ll b,ll M) {ll res=1;a%=M;for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res;}
int main()
{
    string s;
    cin>>s;
    ll ans=0;
    for(int i=0;i<s.size();i++){
        ans=(ans*2+s[i]-'0')%mod;
    }
    ans=ans*pow_mod(2,s.size()-1,mod)%mod;
    cout<<ans;
}
