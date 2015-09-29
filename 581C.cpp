#include<bits/stdc++.h>
#define maxx 111111
using namespace std;
struct node{
    int x,y;
    bool operator <(const node &p) const{
        return y<p.y;
    }
}a[maxx];
int main()
{
    int i,n,k,ans=0;
    cin>>n>>k;
    for(i=1;i<=n;i++) cin>>a[i].x,a[i].y=10-a[i].x%10;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(k>=a[i].y&&a[i].x+a[i].y<=100){
            a[i].x+=a[i].y;
            k-=a[i].y;
        }
    }
    for(i=1;i<=n;i++){
        while(k>=10&&a[i].x+10<=100){
            a[i].x+=10;
            k-=10;
        }
    }
    for(i=1;i<=n;i++) ans+=a[i].x/10;
    cout<<ans<<endl;
}

