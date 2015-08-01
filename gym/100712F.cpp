#include<bits/stdc++.h>
using namespace std;
int f[111111];
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
struct node{
    int x,y,c;
    bool operator< (const node &p)const{
        return c<p.c;
    }
}a[111111];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int i,n,m,ans=0;
        read(n);read(m);
        for(i=1;i<=n;i++) f[i]=i;
        for(i=1;i<=m;i++){
            read(a[i].x);read(a[i].y);read(a[i].c);
        }
        sort(a+1,a+m+1);
        for(i=1;i<=m;i++){
            if(find(a[i].x)!=find(a[i].y)){
                unite(a[i].x,a[i].y);
                ans=max(ans,a[i].c);
            }
        }
        cout<<ans<<endl;
    }
}
