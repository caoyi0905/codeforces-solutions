#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++) if(s[i]=='0') cnt++;
    cout<<min(cnt,int(s.size()-cnt));
}
