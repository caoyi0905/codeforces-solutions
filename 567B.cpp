#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,x,ans=0;
    char ch[3];
    set<int> s;
    cin>>n;
    for(i=1;i<=n;i++){
        getchar();
        cin>>ch>>x;
        if(ch[0]=='-'){
            if(s.count(x)){
                ans=max(ans,int(s.size()));
                s.erase(x);
            }
            else ans++;
        }else if(ch[0]=='+'){
            s.insert(x);
            ans=max(ans,int(s.size()));
        }
    }
    cout<<ans<<endl;
}
