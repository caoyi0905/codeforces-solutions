#include<bits/stdc++.h>
using namespace std;
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
const int MAXN=5000011;
int prime[MAXN+11];
void getPrime()//得到小于等于MAXN的素数，prime[0]存放的是个数
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++)
    {
        if(!prime[i]){
            for(int j=i;j<MAXN;j+=i)
                prime[j]=prime[j/i]+1;
        }
    }
    for(int i=3;i<MAXN;i++) prime[i]+=prime[i-1];
}
int main()
{
    int i,T,a,b;
    getPrime();
    read(T);
    while(T--){
        read(a);read(b);
        printf("%d\n",prime[a]-prime[b]);
    }
}
