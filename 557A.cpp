#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,d,e,f,x,y,z;
int main()
{
    cin>>n>>a>>b>>c>>d>>e>>f;
    x=min(b,n-c-e);
    y=min(d,n-x-e);
    z=n-x-y;
    printf("%d %d %d",x,y,z);;
}
