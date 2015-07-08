#include<bits/stdc++.h>
using namespace std;
const int N=211111;
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int al[N],ar[N];
struct node{
    int mi,ma,id,ans;
    bool operator<(const node p)const{
        if(mi==p.mi) return ma<p.ma;
        return mi<p.mi;
    }
}a[N];
struct bbb{
    int x,id;
    bool operator<(const bbb p)const{
        return x<p.x;
    }
}b[N];
bool cmp (node a,node b){
    return a.id<b.id;
}
int main()
{
    int i,n,m,p=1,q=1;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        read(al[i]);read(ar[i]);
    }
    for(i=1;i<n;i++){
        a[i].mi=al[i+1]-ar[i];
        a[i].ma=ar[i+1]-al[i];
        a[i].id=i;
    }
    sort(a+1,a+n);
    for(i=1;i<=m;i++) read(b[i].x),b[i].id=i;
    sort(b+1,b+n+1);
    while(p<n&&q<=m){
        if(b[q].x>=a[p].mi&&b[q].x<=a[p].ma){
            a[p].ans=b[q].id;
            q++;
            p++;
        }
        else if(b[q].x>a[p].ma){
            return puts("No");
        }
        else if(b[q].x<a[p].mi){
            q++;
        }
    }
    if(p!=n) return puts("No");
    puts("Yes");
    sort(a+1,a+n,cmp);
    for(i=1;i<n;i++){
        cout<<a[i].ans<<' ';
    }
}
