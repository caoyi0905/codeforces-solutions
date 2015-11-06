#include<bits/stdc++.h>
using namespace std;
queue<int> q1,q2;
set<pair<queue<int>,queue<int>>> s;
int main()
{
    int i,n,m,x,flag,cnt=0;
    cin>>x>>n;
    for(i=1;i<=n;i++) cin>>x,q1.push(x);
    cin>>m;
    for(i=1;i<=m;i++) cin>>x,q2.push(x);
    while(1)
    {
        if(q1.empty()){flag=2;break;}
        if(q2.empty()){flag=1;break;}
        if(s.count({q1,q2})){flag=0;break;}
        s.insert({q1,q2});
        int p1=q1.front(),p2=q2.front();q1.pop();q2.pop();
        if(p1>p2){
            q1.push(p2);
            q1.push(p1);
        }else{
            q2.push(p1);
            q2.push(p2);
        }
        cnt++;
    }
    if(!flag) puts("-1");
    else cout<<cnt<<' '<<flag<<endl;
}
