#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,a;
}m[111];
bool cmp(node a,node b){
    return a.x<b.x;
}
int main()
{
    int i,n,c=0,d=0;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>m[i].x>>m[i].a;
        if(m[i].x>0) c++;
        else d++;
    }
    sort(m+1,m+n+1,cmp);
    int sum=0;
    if(c>d){
        for(i=1;i<=d*2+1;i++) sum+=m[i].a;
        cout<<sum;
    }else{
        for(i=n-2*c;i<=n;i++) sum+=m[i].a;
        cout<<sum;
    }
}
