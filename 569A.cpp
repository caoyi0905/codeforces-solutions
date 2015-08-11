#include<bits/stdc++.h>
using namespace std;
int t,s,q,ans;
int main()
{
    cin>>t>>s>>q;
    while(s<t){
        s*=q;
        ans++;
    }
    printf("%d\n",ans);
}
