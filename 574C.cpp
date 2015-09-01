#include<bits/stdc++.h>
using namespace std;
template<typename __ll>
inline void read(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int main()
{
    int n,x,t=-1;
    read(n);
    while(n--){
        read(x);
        while(x%2==0) x/=2;
        while(x%3==0) x/=3;
        if(t==-1) t=x;
        else if(t!=x) return puts("No");
    }
    puts("Yes");
}
