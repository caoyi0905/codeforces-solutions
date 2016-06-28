#include<bits/stdc++.h>
using namespace std;
int aa[101];
int main()
{
    int n,a,ans=0;
    cin>>n>>a;
    a--;
    for(int i=0;i<n;i++) cin>>aa[i];
    if(aa[a]) ans++;
    for(int i=1;i<n;i++){
        int t=0,tt=0;
        if(a+i>=0&&a+i<n){
            if(!aa[a+i]) t++;
            else tt++;
        }
        if(a-i>=0&&a-i<n){
            if(!aa[a-i]) t++;
            else tt++;
        }
        if(!t) ans+=tt;
    }
    cout<<ans;
}
