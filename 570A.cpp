#include<bits/stdc++.h>
using namespace std;
long long a[111];int b[111];
int main()
{
    int i,j,n,m;long long ma=-1,x;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        ma=-1;
        for(j=1;j<=n;j++){
            cin>>a[j];
            if(ma<a[j]){
                ma=a[j];
                x=j;
            }
        }
        b[x]++;
    }
    ma=-1;
    for(i=1;i<=n;i++){
        if(ma<b[i]){
            ma=b[i];
            x=i;
        }
    }
    cout<<x<<endl;
}
