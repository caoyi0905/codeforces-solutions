#include<iostream>
using namespace std;
int main()
{
    string s,t;
    int i,a=0,b=0;
    cin>>s>>t;
    for(i=0;i<s.size();i++) a+=(s[i]=='1');
    for(i=0;i<t.size();i++) b+=(t[i]=='1');
    if(a%2) a++;
    cout<<(a>=b?"YES":"NO");
    return 0;
}
