#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll k,a,b;
    cin>>k>>a>>b;
    ll ans1=a/k*k;
    while(ans1<a) ans1+=k;
    ll ans2=b/k*k;
    while(ans2>b) ans2-=k;
    cout<<(ans2-ans1)/k+1<<endl;
}
