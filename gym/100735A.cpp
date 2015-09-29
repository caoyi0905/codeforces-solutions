#include<bits/stdc++.h>
using namespace std;
set<string>st;
string add(string a,string b){
    if(a.size()<b.size()) swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string c;
    c.resize(max(a.size(),b.size())+1);
    int tmp=0,i;
    for(i=0;i<b.size();i++){
        c[i]=(tmp+a[i]-'0'+b[i]-'0');
        tmp=c[i]/10;
        c[i]=c[i]%10+'0';
    }
    while(i<a.size()){
        c[i]=(tmp+a[i]-'0');
        tmp=c[i]/10;
        c[i]=c[i]%10+'0';
        i++;
    }
    if(tmp==1) c[i++]='1';
    c.resize(i);
    reverse(c.begin(),c.end());
    return c;
}
int main()
{
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    st.insert(s1);
    st.insert(s2);
    st.insert(s3);
    if(st.count(add(s1,s1))) return puts("YES");
    if(st.count(add(s1,s2))) return puts("YES");
    if(st.count(add(s1,s3))) return puts("YES");
    if(st.count(add(s2,s1))) return puts("YES");
    if(st.count(add(s2,s2))) return puts("YES");
    if(st.count(add(s2,s3))) return puts("YES");
    if(st.count(add(s3,s1))) return puts("YES");
    if(st.count(add(s3,s2))) return puts("YES");
    if(st.count(add(s3,s3))) return puts("YES");
    puts("NO");
}
