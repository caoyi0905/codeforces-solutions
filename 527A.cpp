#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,ans=0;
    cin>>a>>b;
    while(a&&b){
        ans+=a/b;
        a=a%b;
        swap(a,b);
    }
    cout<<ans;
}
