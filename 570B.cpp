#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,m;
    cin>>n>>m;
    if(m*2<=n){
        if(m+1>n) cout<<m<<endl;
        else cout<<m+1<<endl;
    }else{
        if(m-1<1) cout<<m<<endl;
        else cout<<m-1<<endl;
    }
}
