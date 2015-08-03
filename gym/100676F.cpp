#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int f[51001];
ll pow_mod(ll a,ll b,ll M) {ll res=1;a%=M;for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res;}
int find(int x){
    return x==f[x]?x:(f[x]=find(f[x]));
}
void unite(int x,int y){
    int f1=find(x),f2=find(y);
    if(f1!=f2) f[f1]=f2;
}
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
    int T,i;
    read(T);
    while(T--){
        int ans=0,n,m,x,y;
        string s;
        read(n);read(m);cin>>s;
        map<int,char> mp;
        int flag=0;
        for(i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]&&s[i]!='?'&&s[n-i-1]!='?'){
                flag=1;
                break;
            }
        }
        for(i=0;i<n;i++) f[i]=i;
        for(i=1;i<=m;i++){
            read(x);read(y);
            if(flag) continue;
            unite(x-1,y-1);
        }
        if(flag){
            puts("0");
            continue;
        }
        for(i=0;i<=(n-1)/2;i++){
            unite(i,n-i-1);
        }
        for(i=0;i<n;i++){
            int father=find(i);
            if(mp.count(father)){
                if(mp[father]!=s[i]&&s[i]!='?'&&mp[father]!='?'){
                    flag=1;
                    break;
                }
                if(mp[father]=='?') mp[father]=s[i];
            }else{
                mp[father]=s[i];
            }
        }
        for(auto i:mp){
            if(i.second=='?') ans++;
        }
        if(flag){
            puts("0");
        }
        else printf("%d\n",int(pow_mod(26LL,ans,mod)));
    }
}
