#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
ll a[2002][2002],s1[4002],s2[4002],ans[2];
int main()
{
    int i,j,n;
    pair<int,int> p[2];
    R(n);
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) R(a[i][j]);
    for(i=0;i<=2*n-2;i++)
        for(j=0;j<=n-1-abs(n-1-i);j++)
        {
            s1[i]+=a[max(0,i-n+1)+1+j][max(0,n-i-1)+1+j];
            s2[i]+=a[max(0,i-n+1)+1+j][min(n,i+1)-j];
        }
    for(i=1;i<=n;i++) for(j=1;j<=n;j++)
    {
        if(ans[(i+j)%2]<=s1[n+i-j-1]+s2[i+j-2]-a[i][j])
        {
            ans[(i+j)%2]=s1[n+i-j-1]+s2[i+j-2]-a[i][j];
            p[(i+j)%2]={i,j};
        }
    }
    cout<<ans[0]+ans[1]<<endl;
    cout<<p[0].first<<' '<<p[0].second<<' '<<p[1].first<<' '<<p[1].second<<endl;
}
