#include<bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
ll hh[2],h[2],a[2],x[2],y[2],t[2];
int main()
{
    int i;long long m;
    cin>>m;
    for(i=0;i<2;i++) cin>>h[i]>>a[i]>>x[i]>>y[i];
    for(i=0;i<2;i++){
        hh[i]=h[i];
        while(hh[i]!=a[i]){
            hh[i]=(x[i]*hh[i]+y[i])%m;
            if(hh[i]==h[i]||t[i]>max(2*m,100000LL)) {return puts("-1");}
            t[i]++;
        }
    }
    if(t[0]==t[1]){
        cout<<t[0];return 0;
    }
    ll cha=t[0]-t[1];ll rt[2]={t[0],t[1]};t[0]=t[1]=0;
    for(i=0;i<2;i++){
        hh[i]=a[i];
        do{
            hh[i]=(x[i]*hh[i]+y[i])%m;
            if(t[i]>max(2*m,1000000LL)) {t[i]=-1;break;}
            t[i]++;
        }while(hh[i]!=a[i]);
    }
    if(t[0]==-1){
        if(rt[0]%rt[1]==0) return cout<<rt[0]<<endl,0;
        return puts("-1");
    }
    if(t[1]==-1){
        if(rt[1]%rt[0]==0) return cout<<rt[1]<<endl,0;
        return puts("-1");
    }
    for(i=0;i<=1000000;i++){
        if((i*t[0]+rt[0])-rt[1]>=0&&(i*t[0]+rt[0]-rt[1])%t[1]==0){
            cout<<i*t[0]+rt[0]<<endl;
            return 0;
        }
    }
    return puts("-1");
}
