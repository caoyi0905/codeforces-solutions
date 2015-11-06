#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (ll)(1e15)
const int N=111;
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
            {
                res.a[i][j]=-inf;
                for(int k=0;k<N;k++)
                    res.a[i][j]=max(res.a[i][j],a[i][k]+y.a[k][j]);
            }
        return res;
    }
    matrix pow(ll e){
        matrix ans(0),t=*this;
        while(e){
            if(e&1) ans=ans*t;
            t=t*t;e>>=1;
        }
        return ans;
    }
};
ll a[111];
int main()
{
    int i,j,k,n,t;
    cin>>n>>t;
    matrix d;
    for(i=0;i<n;i++) cin>>a[i];
    for(int s=0;s<n;s++){
        for(i=0;i<n;i++){
            if(a[i]<a[s]) d.a[s][i]=-inf;
            else{
                d.a[s][i]=1;
                for(j=0;j<i;j++)
                    if(a[j]<=a[i])
                        d.a[s][i]=max(d.a[s][i],d.a[s][j]+1);
            }
        }
    }
    d=d.pow(t);
    ll ans=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) ans=max(ans,d.a[i][j]);
    cout<<ans<<endl;
}
