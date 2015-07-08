#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
priority_queue<int,vector<int>,greater<int> > q2;
int main()
{
    int i,n,m,x,ans1=0,ans2=0;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>x;
        q.push(x);
        q2.push(x);
    }
    for(i=1;i<=n;i++){
        int t=q.top();q.pop();
        ans1+=t;
        if(t>1) q.push(t-1);
    }
    for(i=1;i<=n;i++){
        int t=q2.top();q2.pop();
        ans2+=t;
        if(t>1) q2.push(t-1);
    }
    cout<<ans1<<' '<<ans2<<endl;
}
