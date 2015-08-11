#include<bits/stdc++.h>
#define maxx 1200000
using namespace std;
int vis[maxx+10];
int sump[maxx+10],sumr[maxx+10];
bool check(int x){
    int t=x,p=0;
    while(t){
        int tmp=t%10;
        t/=10;
        p=p*10+tmp;
    }
    return p==x;
}
void init(){
    vis[1]=1;
    for(int i=2;i<=sqrt(maxx);i++)
        if(!vis[i])
            for(int j=i*i;j<maxx;j+=i)
                vis[j]=1;
    for(int i=1;i<maxx;i++){
        sump[i]=sump[i-1]+1-vis[i];
        sumr[i]=sumr[i-1]+check(i);
    }
}
int main()
{
    int i=maxx-10,p,q;
    cin>>p>>q;
    init();
    do{
        if(q*sump[i]<=p*sumr[i]) break;
        i--;
    }while(1);
    cout<<i<<endl;
}
