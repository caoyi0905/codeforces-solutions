#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    map<string,int> mp;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        if(mp[s]) cout<<s<<mp[s]<<endl;
        else cout<<"OK"<<endl;
        mp[s]++;
    }
}
