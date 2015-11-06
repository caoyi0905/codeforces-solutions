#include<bits/stdc++.h>
using namespace std;
string s;
bool gao(string a,string b)
{
    int idx=s.find(a);
    if(idx==string::npos||s.find(b,idx+2)==string::npos) return 0;
    return 1;
}
int main()
{
    cin>>s;
    if(gao("AB","BA")||gao("BA","AB")) puts("YES");
    else puts("NO");

}
