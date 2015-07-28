#include<cstdio>
int main()
{
    int i,n,x,flag=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(x==1) flag=1;
    }
    puts(flag?"-1":"1");
}
