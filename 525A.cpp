#include<bits/stdc++.h>
#define maxx 11111
using namespace std;
map<char,int> mp;
int main(){
    int i,n,ans=0;string s;
    cin>>n>>s;
    for(i=0;i<=2*n-4;i+=2){
        mp[char(s[i]+'A'-'a')]++;
        if(mp[s[i+1]]==0){
            ans++;
        }else{
            mp[s[i+1]]--;
        }
    }
    cout<<ans<<endl;
}
