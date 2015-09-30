#include<iostream>
using namespace std;
int a[111111];
int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    int maxx=0,cnt=1;
    i=2;
    a[n+1]=-1;
    while(i<=n+1){
        if(a[i]>=a[i-1])
            cnt++;
        else{
            maxx=max(maxx,cnt);
            cnt=1;
        }
        i++;
    }
    cout<<max(maxx,cnt);
}
