#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int> mp;
    int i,n,m,x;
    cin>>n>>m;
    vector<int> a(n+1);
    for(i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    vector<int> ans(n+1);
    for(i=1;i<=n;i++){
        ans[i]=mp.size();
        mp[a[i]]--;
        if(mp[a[i]]==0) mp.erase(a[i]);
    }
    while(m--){
        cin>>x;
        cout<<ans[x]<<endl;
    }
}
