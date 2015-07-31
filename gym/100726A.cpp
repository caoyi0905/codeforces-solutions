#include<bits/stdc++.h>
using namespace std;
int vis[10],ans,len;
string s;
map<int,int> mp;
bool isprime(int n){
    if(n<2) return 0;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0) return 0;
    return 1;
}
void dfs(int num){
    if(isprime(num)) mp[num]=1;
    for(int i=-0;i<len;i++){
        if(vis[i]) continue;
        vis[i]=1;
        dfs(num*10+s[i]-'0');
        vis[i]=0;
    }
}
int main()
{
    int c,i;
    cin>>c;
    while(cin>>s){
        ans=0;
        len=s.length();
        mp.clear();
        for(i=0;i<len;i++){
            vis[i]=1;
            dfs(s[i]-'0');
            vis[i]=0;
        }
        for(auto i: mp){
            if(isprime(i.first)) ans++;
        }
        cout<<ans<<endl;
    }
}
