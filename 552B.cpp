#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i=1,n,t=9,ans=0;
    cin>>n;
    while(n>t){
        ans+=i*t;
        n-=t;
        i++;t*=10;
    }
    ans+=i*n;
    cout<<ans<<endl;
}
