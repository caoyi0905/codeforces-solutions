#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int f[1001][1001][2];
char g[1001][1001][2];
int n,x,k;
void gao(int x,int y) {
	if(x==1&&y==1) return ;
	if(g[x][y][k]) gao(x-1,y),putchar('D');
	else gao(x,y-1),putchar('R');
}
int main()
{
    int i,j,n;
    R(n);
    memset(f,0,sizeof f);
    for(i=2;i<=n;i++) f[0][i][0]=f[0][i][1]=f[i][0][0]=f[i][0][1]=inf;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            R(k);
            if(!k) x=i;
            else{
                while(k%2==0) ++f[i][j][0],k/=2;
                while(k%5==0) ++f[i][j][1],k/=5;
            }
            for(k=0;k<2;k++)
                if((g[i][j][k]=f[i-1][j][k]<f[i][j-1][k])) f[i][j][k]+=f[i-1][j][k];
                else f[i][j][k]+=f[i][j-1][k];
        }
    k=f[n][n][1]<f[n][n][0];
    if(x&&f[n][n][k]>1){
        puts("1");
        for(i=2;i<=x;i++) putchar('D');
        for(i=2;i<=n;i++) putchar('R');
        for(i=x+1;i<=n;i++) putchar('D');
    }else printf("%d\n",f[n][n][k]),gao(n,n);
}
