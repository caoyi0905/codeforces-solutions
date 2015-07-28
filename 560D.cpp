#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
using namespace std;
string gao(string s)
{
    int len=SZ(s);
    if(len&1) return s;
    string s1=gao(s.substr(0,len>>1)),s2=gao(s.substr(len>>1));
    return s1<s2?(s1+s2):(s2+s1);
}
int main()
{
    string s,t;
    cin>>s>>t;
    puts(gao(s)==gao(t)?"YES":"NO");
}
