#include<bits/stdc++.h>
#define maxx 2011
#define mod 1000000007
#define ll long long
using namespace std;
struct node{
    int r,c;
}p[maxx];
ll sum[maxx],fac[310000],inv[310000];
ll mul(ll x,ll y,ll z){return (x*y-(ll)(x/(long double)z*y+1e-3)*z+z)%z;}
ll pow_mod(ll a,ll b,ll M) {ll res=1;a%=M;for(;b;b>>=1){if(b&1)res=mul(res,a,M);a=mul(a,a,M);}return res;}
ll C(ll n,ll k){
    return fac[n]*inv[k]%mod*inv[n-k]%mod;
}
bool cmp(node a,node b){
    if(a.r==b.r) return a.c<b.c;
    return a.r<b.r;
}
void init(int n,ll c)
{
    int i;fac[0]=inv[0]=1;
    for(i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%mod;
    inv[c]=pow_mod(fac[c],mod-2,mod);
    for(i=c-1;i>0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
int main()
{
    int h,w,n,i,j;
    cin>>h>>w>>n;
    init(210000,max(h,w));
    for(i=1;i<=n;i++)
        cin>>p[i].r>>p[i].c;
    p[n+1].r=h,p[n+1].c=w;
    sort(p+1,p+n+2,cmp);
    for(i=1;i<=n+1;i++){
        sum[i]=C(p[i].r+p[i].c-2,p[i].c-1);
        for(j=1;j<i;j++){
            if(p[i].c>=p[j].c){
                sum[i]=(sum[i]-sum[j]*C(p[i].r-p[j].r+p[i].c-p[j].c,p[i].c-p[j].c)%mod)%mod;
                if(sum[i]<0) sum[i]+=mod;
            }
        }
    }
    cout<<sum[n+1]<<endl;
}
