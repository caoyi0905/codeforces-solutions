#include<bits/stdc++.h>
using namespace std;
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
pair<int,int> a[100001];
int main()
{
    int i,n;
    R(n);
    for(i=1;i<=n;i++) R(a[i].first),R(a[i].second);
    int ans=0,k=-0x3f3f3f3f;
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        if(a[i].first-a[i].second>k)
        {
            k=a[i].first;
            ans++;
        }
        else if(i==n||a[i].first+a[i].second<a[i+1].first)
        {
            k=a[i].first+a[i].second;
            ans++;
        }
        else k=a[i].first;
    }
    printf("%d",ans);
}
