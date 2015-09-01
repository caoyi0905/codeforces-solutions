#include<bits/stdc++.h>
using namespace std;
int a[111],ans;
int main()
{
    int i,n,hehe;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    hehe=a[1];
    sort(a+2,a+n+1);
    while(a[n]>=hehe){
        hehe++;
        ans++;
        a[n]--;
        sort(a+2,a+n+1);
    }
    cout<<ans;
}
