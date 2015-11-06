#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
int t[26],ca[26],cb[26],ma,mb;
int main()
{
    string a,b,c;
    cin>>c>>a>>b;
    for(auto i:c) t[i-'a']++;
    for(auto i:a) ca[i-'a']++;
    for(auto i:b) cb[i-'a']++;
    int sum=111111;
    rep(i,0,26) if(ca[i]) sum=min(sum,t[i]/ca[i]);
    rep(i,0,sum+1){
        int res=111111;
        rep(j,0,26) if(cb[j]) res=min(res,(t[j]-ca[j]*i)/cb[j]);
        if(i+res>ma+mb) ma=i,mb=res;
    }
    rep(i,0,ma) cout<<a;
    rep(i,0,mb) cout<<b;
    rep(i,0,26) rep(j,0,t[i]-ca[i]*ma-cb[i]*mb) cout<<char(i+'a');
}
