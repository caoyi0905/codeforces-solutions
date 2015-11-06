#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Fraction{
public:
    ll a,b;
    Fraction(){a=0;b=1;}
    Fraction(ll x){
        a=x;b=1;
    }
    Fraction(int x){
        a=x;b=1;
    }
    Fraction(ll x,ll y){
        ll d=__gcd(x,y);
        if(d<0) d*=-1;
        if(y==0) assert(0);
        if(x==0){
            a=0;b=1;
        }
        else if(y<0){
            x*=-1,y*=-1;
            a=x/d;
            b=y/d;
        }
        else{
            a=x/d;
            b=y/d;
        }
    }

    ll toNum()
    {
        return a/b;
    }

    Fraction operator +(const Fraction &p)const{
        return Fraction(a*p.b+b*p.a,b*p.b);
    }

    Fraction operator -(const Fraction &p)const{
        return Fraction(a*p.b-b*p.a,b*p.b);
    }

    Fraction operator *(const Fraction &p)const{
        return Fraction(a*p.a,b*p.b);
    }

    Fraction operator *(const ll &p)const{
        return Fraction(a*p,b);
    }

    Fraction operator /(const Fraction &p)const{
        return Fraction(a*p.b,b*p.a);
    }

    Fraction operator /(const ll &p)const{
        return Fraction(a,b*p);
    }

    bool operator <(const Fraction &p)const{
        if(a*p.b<b*p.a) return 1;
        return 0;
    }

    bool operator <=(const Fraction &p)const{
        if(a*p.b<=b*p.a) return 1;
        return 0;
    }

    bool operator >(const Fraction &p)const{
        if(a*p.b>b*p.a) return 1;
        return 0;
    }

    bool operator >=(const Fraction &p)const{
        if(a*p.b>=b*p.a) return 1;
        return 0;
    }

    friend inline ostream&operator<<(ostream &os,const Fraction& p)
    {
        os<<p.a<<'/'<<p.b;
        return os;
    }

};
Fraction getone(int n){
    Fraction r(0);
    Fraction ONE(1);
    ll x;
    vector<ll> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    for(int i=v.size()-1;i>=0;i--){
        if(i!=v.size()-1) r=ONE/r;
        r=Fraction(v[i])+r;
    }
    return r;
}
void dfs(Fraction x,vector<ll> &ans){
    ll tmp=x.a/x.b;
    ans.push_back(tmp);
    if(x.b==1) return ;
    Fraction ONE(1);
    Fraction f=ONE/(x-Fraction(tmp));
    dfs(f,ans);
}
void gao(Fraction x){
    vector<ll> ans;
    dfs(x,ans);
    for(int i=0;i<ans.size();i++)
        printf("%I64d%c",ans[i],i==ans.size()-1?'\n':' ');
}
int main()
{
    int n1,n2,cas=1;
    while(cin>>n1>>n2&&(n1||n2)){
        Fraction r1=getone(n1);
        Fraction r2=getone(n2);
        printf("Case %d:\n",cas++);
        gao(r1+r2);
        gao(r1-r2);
        gao(r1*r2);
        gao(r1/r2);
    }
}
