#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main()
{
    int i,n,ans=0;
    string s;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>s;
        m[s]++;
    }
    for(auto &i: m){
        ans=max(i.second,ans);
    }
    cout<<ans<<endl;
}
