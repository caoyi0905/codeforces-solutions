#include<bits/stdc++.h>
#define maxx 111111
using namespace std;
int n,a[maxx],mn[maxx][19],mx[maxx][19];
void pre()
{
     for(int i=1;i<=n;i++)
        mx[i][0]=mn[i][0]=a[i];
     int t=log(n)/log(2);
    for(int i=1;i<=t;i++)
       for(int j=n;j>0;j--)
       {
               mx[j][i]=mx[j][i-1];
               if(j+(1<<(i-1))<=n)
               mx[j][i]=max(mx[j][i],mx[j+(1<<(i-1))][i-1]);
       }
    for(int i=1;i<=t;i++)
       for(int j=n;j>0;j--)
       {
               mn[j][i]=mn[j][i-1];
               if(j+(1<<(i-1))<=n)
               mn[j][i]=min(mn[j][i],mn[j+(1<<(i-1))][i-1]);
       }
}
int rmq(int l,int r)
{
    int m=log(r-l+1)/log(2);
    int a=max(mx[l][m],mx[r-(1<<m)+1][m]);
    return a;
}
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    pre();
    for(int i=1;i<n;i++){
        cout<<max(0,rmq(i+1,n)-a[i]+1)<<' ';
    }
    cout<<0<<endl;
}
