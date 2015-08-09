#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,x1,x2,y1,y2,s=0;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x1>>y1>>x2>>y2;
        s+=(x2-x1+1)*(y2-y1+1);
    }
    cout<<s;
}
