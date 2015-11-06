#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
const int N=4;
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
                    res.a[i][j]=(res.a[i][j]+a[i][k]*y.a[k][j])%mod;
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
int main()
{
    int n;
    cin>>n;
    matrix m;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            m.a[i][j]=(i==j?0:1);
    m=m.pow(n);
    cout<<m.a[3][3];
}
