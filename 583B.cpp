#include<bits/stdc++.h>
using namespace std;
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int a[1111];
int main()
{
    int i,n;
    R(n);
    for(i=1;i<=n;i++) R(a[i]);
    int sum=0,cnt=n,tt=1;
    while(cnt){
        if(tt&1){
            for(i=1;i<=n;i++){
                if(a[i]!=-1&&a[i]<=sum){
                    a[i]=-1;
                    cnt--;
                    sum++;
                }
            }
        }else{
            for(i=n;i>=1;i--)
                if(a[i]!=-1&&a[i]<=sum){
                    a[i]=-1;
                    cnt--;
                    sum++;
                }
        }
        tt++;
    }
    cout<<tt-2<<endl;
}
