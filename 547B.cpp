#include<bits/stdc++.h>
using namespace std;
int a[211111];
pair<int,int> m[2111111];
map<int,int>mp;
int main()
{
    int i,n,s=0,t;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    m[++s]=make_pair(0,0);
    for(i=1;i<=n+1;i++){
        if(s==0||a[i]>m[s].first){
            m[++s]=make_pair(a[i],i);
        }else{
            while(s>0&&a[i]<m[s].first){
                if(!mp.count(i-m[s].second)) mp[i-m[s].second]=m[s].first;
                mp[i-m[s].second]=max(mp[i-m[s].second],m[s].first);
                s--;
            }
        }
    }
    i=1;
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
        while(it->first>=i){
            cout<<it->second<<" ";
            i++;
        }
    }
}
