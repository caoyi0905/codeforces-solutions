#include<bits/stdc++.h>
using namespace std;
int a[201];
int main()
{
    int i,n,k;
    cin>>n>>k;
    for(i=1;i<=n*2+1;i++) cin>>a[i];
    for(i=1;i<=n*2+1;i++){
        if(k&&a[i]>a[i-1]+1&&a[i]>a[i+1]+1) printf("%d ",a[i]-1),k--;
        else printf("%d ",a[i]);
    }
}
