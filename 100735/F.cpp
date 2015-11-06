#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
typedef long long ll;
typedef pair<ll,ll> PLL;
const ll mod=1000000007;
// head
namespace Factor{
    const int N=1010000;
    ll C,fac[10010],n,mut,a[1001000];
    int T,cnt,i,l,prime[N],p[N],psize,_cnt;
    ll _e[100],_pr[100];
    vector<ll> d;
    inline ll mul(ll x,ll y,ll z){return (x*y-(ll)(x/(long double)z*y+1e-3)*z+z)%z;}
    void prime_table(){
        int i,j,tot,t1;
        for(i=1;i<=psize;i++) p[i]=i;
        for(i=2,tot=0;i<=psize;i++){
            if(p[i]==i) prime[++tot]=i;
            for(j=1;j<=tot&&(t1=prime[j]*i)<=psize;j++){
                p[t1]=prime[j];
                if(i%prime[j]==0) break;
            }
        }
    }
    void init(int ps){
        psize=ps;
        prime_table();
    }
    ll powl(ll a,ll n,ll p){
        ll ans=1;
        for(;n;n>>=1){
            if(n&1) ans=mul(ans,a,p);
            a=mul(a,a,p);
        }
        return ans;
    }
    bool witness(ll a,ll n){
        int t=0;
        ll u=n-1;
        for(;~u&1;u>>=1) t++;
        ll x=powl(a,u,n),_x=0;
        for(;t;t--){
            _x=mul(x,x,n);
            if(_x==1&&x!=1&&x!=n-1) return 1;
            x=_x;
        }
        return _x!=1;
    }
    bool miller(ll n){
        if(n<2) return 0;
        if(n<=psize) return p[n]==n;
        if(~n&1) return 0;
        for(int j=0;j<=7;j++) if(witness(rand()%(n-1)+1,n)) return 0;
        return 1;
    }
    ll rho(ll n){
        while(1){
            ll X=rand()%n,Y,Z,T=1,*lY=a,*lX=lY;
            int tmp=20;
            C=rand()%10+3;
            X=mul(X,X,n)+C;*(lY++)=X;lX++;
            Y=mul(X,X,n)+C;*(lY++)=Y;
            for(;X!=Y;){
                ll t=X-Y+n;
                Z=mul(T,t,n);
                if(Z==0) return __gcd(T,n);
                tmp--;
                if(tmp==0){
                    tmp=20;
                    Z=__gcd(Z,n);
                    if(Z!=1&&Z!=n) return Z;
                }
                T=Z;
                Y=*(lY++)=mul(Y,Y,n)+C;
                Y=*(lY++)=mul(Y,Y,n)+C;
                X=*(lX++);
            }
        }
    }
    void _factor(ll n){
        for(int i=0;i<cnt;i++){
            if(n%fac[i]==0) n/=fac[i],fac[cnt++]=fac[i];
          }
        if(n<=psize){
            for(;n!=1;n/=p[n]) fac[cnt++]=p[n];
            return;
        }
        if(miller(n)) fac[cnt++]=n;
        else{
            ll x=rho(n);
            _factor(x);_factor(n/x);
        }
    }
    void dfs(ll x,int dep){
        if(dep==_cnt) d.push_back(x);
        else{
            dfs(x,dep+1);
            for(int i=1;i<=_e[dep];i++) dfs(x*=_pr[dep],dep+1);
        }
    }
    void norm(){
        sort(fac,fac+cnt);
        _cnt=0;
        rep(i,0,cnt) if(i==0||fac[i]!=fac[i-1]) _pr[_cnt]=fac[i],_e[_cnt++]=1;
            else _e[_cnt-1]++;
    }
    vector<ll> getd(){
        d.clear();dfs(1,0);
        return d;
    }
    vector<ll> factor(ll n){
        cnt=0;_factor(n);norm();
        return getd();
    }
    vector<PLL> factorG(ll n){
        cnt=0;_factor(n);norm();
        vector<PLL> d;
        rep(i,0,_cnt) d.push_back(make_pair(_pr[i],_e[i]));
        return d;
    }
    bool is_primitive(ll a,ll p){
        vector<PLL> D=factorG(p-1);
        rep(i,0,D.size()) if(powl(a,(p-1)/D[i].first,p)==1) return 0;
        return 1;
    }
}
int main()
{
    Factor::init(200000);
    ll n;
    cin>>n;
    vector<ll> c=Factor::factor(n);
    cout<<c.size()<<endl;
}
