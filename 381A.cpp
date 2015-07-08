#include<bits/stdc++.h>
#define maxx 1001
using namespace std;
int a[maxx],b[2];
int main()
{
    int i,j,n,t=0;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    i=1;j=n;
    while(i<=j){
        if(a[i]>a[j]){
            b[t&1]+=a[i];
            i++;
        }else{
            b[t&1]+=a[j];
            j--;
        }
        t++;
    }
    cout<<b[0]<<' '<<b[1]<<endl;
}
