#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--){
        int x,y,z;
        cin>>x>>y>>z;
        if(x+y+z!=180) puts("NO");
        else{
            if(max(max(x,y),z)==180||min(min(x,y),z)==0) puts("NO");
            else puts("YES");
        }
    }
}
