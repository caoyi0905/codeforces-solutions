#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
map<int,int>mp,mp2;
int main()
{
    int i,n,x,y;
    ll sum=0;
    cin>>n;
    for(i=1;i<=n;i++){
        R(x);R(y);
        mp[x-y]++;
        mp2[x+y]++;
    }
    for(auto it:mp){
        sum+=(it.second-1)*it.second/2;
    }
    for(auto it:mp2){
        sum+=(it.second-1)*it.second/2;
    }
    cout<<sum;
}
