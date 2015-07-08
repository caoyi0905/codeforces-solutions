#include<bits/stdc++.h>
#define maxx 211111
using namespace std;
int a[maxx],s[maxx];
int main(){
    int i,m,x;string str;
    cin>>str>>m;int len=str.size();
    for(i=1;i<=m;i++){
        cin>>x;
        a[x]++;a[len-x+2]--;
    }
    for(i=1;i<=len;i++) s[i]=s[i-1]+a[i];
    for(i=1;i<=len;i++){
        if(s[i]%2==0) cout<<str[i-1];
        else cout<<str[len-i];
    }
}
