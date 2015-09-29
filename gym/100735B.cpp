#include<bits/stdc++.h>
#define mod 1000000009
#define ll long long
using namespace std;
const int N=21;
struct matrix
{
    ll a[N][N];
    matrix(){memset(a,0,sizeof(a));}
    matrix(ll d){
        memset(a,0,sizeof(a));
        for(int i=0;i<N;i++) a[i][i]=d;
    }
    matrix operator *(const matrix &y)const{
        matrix res;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                for(int k=0;k<N;k++)
                    res.a[i][j]=(res.a[i][j]+a[i][k]%mod*y.a[k][j]%mod)%mod;
        return res;
    }
    matrix pow(ll e){
        matrix ans(1),t=*this;
        while(e){
            if(e&1) ans=ans*t;
            t=t*t;e>>=1;
        }
        return ans;
    }
};
int k[N],f[N];
int main()
{
    ll i,n,c;ll m;
    matrix ans;
    cin>>n>>m>>c;
    for(i=1;i<=n;i++) cin>>f[i];
    for(i=0;i<c;i++) cin>>k[i];
    if(m<=n){
        cout<<f[i]%mod;
        return 0;
    }
    matrix t;
    for(i=0;i<c;i++) t.a[0][k[i]-1]=1;
    for(i=1;i<n;i++) t.a[i][i-1]=1;
    for(i=0;i<n;i++) ans.a[i][0]=f[n-i];
    cout<<(t.pow(m-n)*ans).a[0][0];
}
