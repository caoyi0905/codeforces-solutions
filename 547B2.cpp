#include<bits/stdc++.h>
#define maxx 211111
using namespace std;
int n,a[maxx],mn[maxx][19];
void pre()
{
    for(int i=1;i<=n;i++)
        mn[i][0]=a[i];
    int t=log(n)/log(2);
    for(int i=1;i<=t;i++)
       for(int j=n;j>0;j--)
       {
               mn[j][i]=mn[j][i-1];
               if(j+(1<<(i-1))<=n)
               mn[j][i]=min(mn[j][i],mn[j+(1<<(i-1))][i-1]);
       }
}
int rmq(int l,int r)
{
    int m=log(r-l+1)/log(2);
    int b=min(mn[l][m],mn[r-(1<<m)+1][m]);
    return b;
}
bool check(int id,int x,int t){
    if(rmq(id,x)<a[t]) return 0;
    return 1;
}
int mp[311111];
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++) read(a[i]);
    pre();
    for(i=1;i<=n;i++){
        int l=i,r=n,ans;
        while(l<=r){
            int mid=l+r>>1;
            if(check(i,mid,i)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        int tmp=ans;
        l=1,r=i,ans=1;
        while(l<=r){
            int mid=l+r>>1;
            if(!check(mid,i,i)) l=mid+1;
            else ans=mid,r=mid-1;
        }
        mp[tmp-ans+1]=max(mp[tmp-ans+1],a[i]);
    }
    for(i=n;i>=1;i--){
        mp[i]=max(mp[i+1],mp[i]);
    }
    for(i=1;i<=n;i++) printf("%d ",mp[i]);
}
