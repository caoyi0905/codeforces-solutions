#include<bits/stdc++.h>
#define maxx 11111
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;
map<pair<char,char>,int> mp;
map<char,int> m;
int main(){
    int i,n,hehe=0;string s,t;
    cin>>n>>s>>t;
    for(i=0;i<n;i++) if(s[i]!=t[i]) hehe++;
    for(i=0;i<n;i++) if(s[i]!=t[i]){
        if(!mp.count(make_pair(t[i],s[i])))
            mp[make_pair(s[i],t[i])]=i;
        else{
            cout<<hehe-2<<endl<<mp[make_pair(t[i],s[i])]+1<<" "<<i+1<<endl;
            return 0;
        }
    }
    for(i=0;i<n;i++) if(s[i]!=t[i]){
        m[t[i]]=i;
    }
    for(i=0;i<n;i++) if(s[i]!=t[i]){
        if(m.count(s[i])){
            cout<<hehe-1<<endl<<i+1<<' '<<m[s[i]]+1<<endl;
            return 0;
        }
    }
    printf("%d\n-1 -1",hehe);
}
