#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int d,dd,n,m;
int gao(int x){
    int ans=0;
    for(int i=0;i<v.size();i++)
        ans+=abs(v[i]-v[x])/d;
    return ans;
}
int main()
{
    cin>>n>>m>>d;
    v.resize(n*m);
    for(int i=0;i<v.size();i++) cin>>v[i];
    if(n==1&&m==1) return puts("0");
    for(int i=0;i+1<v.size();i++){
        if(dd==0) dd=v[i+1]-v[i];
        else dd=__gcd(dd,v[i+1]-v[i]);
    }
    if(dd%d) return puts("-1");
    sort(v.begin(),v.end());
    if(v.size()%2) cout<<gao(v.size()/2);
    else cout<<min(gao(v.size()/2-1),gao(v.size()/2));
}
