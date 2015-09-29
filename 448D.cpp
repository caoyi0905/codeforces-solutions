#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
ll gao(ll x){
    ll t=0;
    for(int i=1;i<=n;i++){
        ll h=x/i;
        t+=min(m,h);
    }
    return t;
}
int main()
{
    cin>>n>>m>>k;
    ll l=1,r=n*m+1,ans;
    while(l<=r){
        ll mid=l+r>>1;
        if(gao(mid)>=k){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<ans;
}
