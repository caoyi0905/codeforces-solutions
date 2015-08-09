#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,f[233]={1,1};
int main(){
    for(int i=2;i<60;i++)f[i]=f[i-1]+f[i-2];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        if(k>f[n-i]){
            k-=f[n-i];
            printf("%d %d ",i+1,i);
            i++;
        }else{
            printf("%d ",i);
        }
    }
    return 0;
}
