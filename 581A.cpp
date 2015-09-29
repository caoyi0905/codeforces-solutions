#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,a,b;
    cin>>a>>b;
    int c=min(a,b);
    a-=c;b-=c;
    cout<<c<<' '<<a/2+b/2;
}
