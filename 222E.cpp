#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
using namespace std;
const int N=55;
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
int num(char c){
    if(c>='a'&&c<='z') return c-'a';
    return c-'A'+26;
}
int main()
{
    ll n,m,k;
    char str[3];
    cin>>n>>m>>k;
    matrix a,b;
    for(int i=0;i<m;i++){
        b.a[i][0]=1;
        for(int j=0;j<m;j++)
            a.a[i][j]=1;
    }
    for(int i=0;i<k;i++){
        scanf("%s",str);
        a.a[num(str[0])][num(str[1])]=0;

    }
    for(n--;n;n>>=1){
        if(n&1) b=a*b;
        a=a*a;
    }
    ll ans=0;
    for(int i=0;i<m;i++) ans=(ans+b.a[i][0])%mod;
    cout<<ans<<endl;
}
