#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,m;
    cin>>n>>m;
    if(n==1&&m==1) cout<<1;
    else if(m*2<=n){
        cout<<m+1;
    }else{
        cout<<m-1;
    }
}
