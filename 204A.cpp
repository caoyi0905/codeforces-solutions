#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll x)
{
    if(x<10) return x;
    ll s=x,f=x/10+9,g;
    while(x>0) g=x,x/=10;
    if(g>s%10) f--;
    return f;
}
int main()
{
    ll l,r;
    cin>>l>>r;
    cout<<f(r)-f(l-1);
}
