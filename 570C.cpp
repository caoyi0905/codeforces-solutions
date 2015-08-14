#include<bits/stdc++.h>
#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)
using namespace std;
char c[11];
template<typename __ll>
inline void read(__ll &m)
{
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
char str[300011];
int main()
{
    int i,n,m,x;
    read(n);read(m);
    reader(str+1);
    int ans=0,cnt=0;
    for(i=1;i<=n+1;i++){
        if(str[i]!='.'&&cnt!=0){
            ans+=cnt-1;
            cnt=0;
        }
        if(str[i]=='.') cnt++;
    }
    for(int j=1;j<=m;j++){
        read(x),reader(c);
        if(c[0]=='.'&&str[x]!='.'){
            if(str[x-1]=='.') ans++;
            if(str[x+1]=='.') ans++;
        }
        else if(c[0]!='.'&&str[x]=='.'){
            if(str[x-1]=='.') ans--;
            if(str[x+1]=='.') ans--;
        }
        str[x]=c[0];
        writer(ans,'\n');
    }
}
