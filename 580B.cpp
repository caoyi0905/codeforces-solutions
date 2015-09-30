#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
struct node{
    ll m,s;
    bool operator <(const node &p)const{
        return m<p.m;
    }
}a[111111];
ll sum[111111],tt[111111];
int main()
{
    int i,n,d;
    cin>>n>>d;
    for(i=1;i<=n;i++) cin>>a[i].m>>a[i].s;
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].s,tt[i]=a[i].m;
    ll ans=0;
    for(int i=1;i<=n;i++){
        int t=lower_bound(tt+1,tt+n+1,tt[i]+d)-tt;
        ans=max(ans,sum[t-1]-sum[i-1]);
    }
    cout<<ans<<endl;
}
