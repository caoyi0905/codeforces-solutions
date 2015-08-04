#include<bits/stdc++.h>
using namespace std;
struct P{
    int x,y;
}p[2005];
bool check(int i,int j,int k){
    int x1,x2,y1,y2;
    x1=p[i].x-p[j].x,x2=p[j].x-p[k].x;
    y1=p[i].y-p[j].y,y2=p[j].y-p[k].y;
    return x1*y2!=y1*x2;
}
int main()
{
    int n,ans=0,i,j,k;
    cin>>n;
    for(i=1;i<=n;++i) scanf("%d%d",&p[i].x,&p[i].y);
    for(i=1;i<=n;++i)
        for(j=i+1;j<=n;++j)
            for(k=j+1;k<=n;++k)
                if(check(i,j,k)) ++ans;
    printf("%d\n",ans);
    return 0;
}
