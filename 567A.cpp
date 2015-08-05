#include<bits/stdc++.h>
using namespace std;
int x[111111];
int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>x[i];
    for(i=1;i<=n;i++){
        if(i==1){
            cout<<x[2]-x[1]<<' '<<x[n]-x[1]<<endl;
        }else if(i==n){
            cout<<x[n]-x[n-1]<<' '<<x[n]-x[1]<<endl;
        }else{
            cout<<min(x[i]-x[i-1],x[i+1]-x[i])<<' '<<max(x[n]-x[i],x[i]-x[1])<<endl;
        }
    }
}
