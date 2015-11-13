#include<stdio.h>
#define N 111111
#define ll long long
ll c[12][N+3];
void add(int t,int x,ll v){for(;x<=N;x+=x&(-x)) c[t][x]+=v;}
ll sum(int t,int x){
    ll s=0;
    for(;x;x&=x-1) s+=c[t][x];
    return s;
}
int a[N];
int main()
{
    int i,j,n,k;
    scanf("%d%d",&n,&k);k++;
    for(i=1;i<=n;i++) scanf("%d",a+i),a[i]++;
    add(0,1,1);
    for(i=1;i<=n;i++)
        for(j=1;j<=k;j++)
            add(j,a[i],sum(j-1,a[i]-1));
    printf("%I64d",sum(k,N));
}
