#include<bits/stdc++.h>
#define maxx 200001
using namespace std;
int n,a[maxx],mx[maxx][14],sum[maxx],pre[maxx];
void init(int n)
{
     for(int i=1;i<=n;i++)
        mx[i][0]=pre[i];
     int t=log(n)/log(2);
    for(int i=1;i<=t;i++)
       for(int j=n;j>0;j--)
       {
               mx[j][i]=mx[j][i-1];
               if(j+(1<<(i-1))<=n)
               mx[j][i]=max(mx[j][i],mx[j+(1<<(i-1))][i-1]);
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
	int i,j,k;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		sum[i]=sum[i-1]+a[i];
	}
	for(i=1;i+k-1<=n;i++)
		pre[i]=sum[i+k-1]-sum[i-1];
	int max=-1,x=1,y=1;
	init(n-k+1);
	for(i=1;i+k<=n-k+1;i++){
        int t=rmq(i+k,n-k+1);
        if(pre[i]+t>max){
            max=pre[i]+t;
            x=i;
            y=t;
        }
    }
    for(i=x+k;i+k-1<=n;i++) if(max-pre[x]==pre[i]){y=i;break;}
	printf("%d %d",x,y);
}
