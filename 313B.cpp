#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    vector<int> v(s.size());
    for(int i=1;i<s.size();i++) v[i]=v[i-1]+(s[i]==s[i-1]);
    int m,l,r;
    cin>>m;
    while(m--){
        cin>>l>>r;
        printf("%d\n",v[r-1]-v[l-1]);
    }
}
