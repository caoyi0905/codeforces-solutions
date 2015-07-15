#include<bits/stdc++.h>
using namespace std;
int a[111111];
map<int,int> mp;
int st[1111111];
int ed[1111111];
int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
        if(st[a[i]]==0) st[a[i]]=i;
        ed[a[i]]=i;
    }
    int cnt=-1,ans=99999999,p,q;
    for(auto &i:mp) cnt=max(cnt,i.second);
    for(auto &i:mp){
        if(i.second==cnt){
            if(ans>ed[i.first]-st[i.first]){
                ans=ed[i.first]-st[i.first];
                p=st[i.first];q=ed[i.first];
            }
        }
    }
    cout<<p<<" "<<q<<endl;
}
