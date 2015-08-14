#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,ans;
    cin>>a>>b>>c;
    ans=min(a,min(b,c));
    a-=ans;b-=ans;c-=ans;
    if(a%3+b%3+c%3==4&&ans)
        ans++;
    ans+=a/3+b/3+c/3;
    cout<<ans<<endl;
    return 0;
}
