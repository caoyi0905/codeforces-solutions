#include<bits/stdc++.h>
using namespace std;
int main()
{
    int y,w,x;
    cin>>y>>w;
    x=min(7-y,7-w);
    int d=__gcd(x,6);
    cout<<x/d<<"/"<<6/d<<endl;
}
