#include<bits/stdc++.h>
using namespace std;
struct node{
    string s;
    int a,b;
    bool operator <(const node &p) const{
        if(a==p.a) return b<p.b;
        return a>p.a;
    }
}m[111];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int i,n;
        cin>>n;
        for(i=1;i<=n;i++) cin>>m[i].s>>m[i].a>>m[i].b;
        sort(m+1,m+n+1);
        cout<<m[1].s<<endl;
    }
}
