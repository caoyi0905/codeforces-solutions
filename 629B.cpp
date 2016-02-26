#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> a;
vector<pair<int,int>> b;
int main()
{
    int i,n,l,r;char ch;
    int ans=0;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>ch>>l>>r;
        if(ch=='M') a.push_back(make_pair(l,r));
        else b.push_back(make_pair(l,r));
    }
    for(i=1;i<=366;i++){
        int cnt1=0,cnt2=0;
        for(auto it: a){
            if(it.first<=i&&i<=it.second) cnt1++;
        }
        for(auto it: b){
            if(it.first<=i&&i<=it.second) cnt2++;
        }
        ans=max(ans,min(cnt1,cnt2));
    }
    cout<<ans*2;
}
