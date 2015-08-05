#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
ll a[211111];
int cnt[211111];
ll ans=0;
map<int,int> mp,mp2;
int main()
{
    int i,n;ll k;
    cin>>n>>k;
    for(i=1;i<=n;i++) read(a[i]);
    if(k==1){
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++){
            int st=lower_bound(a+i+1,a+n+1,a[i]*k)-a;
            if(a[st]!=a[i]*k) continue;
            int ed=lower_bound(a+i+1,a+n+1,a[i]*k+1)-a;
            ll l1=ed-st;
            ans+=l1*(l1-1)/2;
        }
        cout<<ans<<endl;
        return 0;
    }
    for(i=1;i<=n;i++) mp2[a[i]]++;
    for(i=1;i<=n;i++){
        if(a[i]%k!=0){
            mp[a[i]]++;
            continue;
        }
        if(a[i]*k>1000000000) continue;
        mp2[a[i]]--;
        int t=mp2[a[i]*k];
        if(t!=0){
            ans+=(ll)mp[a[i]/k]*t;
        }
        mp[a[i]]++;
    }
    cout<<ans<<endl;
}
