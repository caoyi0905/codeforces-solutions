#include<bits/stdc++.h>
using namespace std;
string str;
map<char,char>mp;
char Find(char c){
    for(char ch='a';ch<='z';ch++) if(mp[ch]==c) return ch;
}
int main()
{
    int i,n,m;
    char a,b;
    cin>>n>>m;
    cin>>str;
    for(char ch='a';ch<='z';ch++) mp[ch]=ch;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        int pa=Find(a),pb=Find(b);
        mp[pa]=b;mp[pb]=a;
    }
    for(i=0;i<str.size();i++) str[i]=mp[str[i]];
    cout<<str;
}
