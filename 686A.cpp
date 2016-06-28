#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    long long m,x,cnt=0;
    cin>>n>>m;
    char ch;
    for(i=1;i<=n;i++){
        cin>>ch>>x;
        if(ch=='+') m+=x;
        else{
            if(m>=x) m-=x;
            else cnt++;
        }
    }
    cout<<m<<' '<<cnt<<endl;
}

