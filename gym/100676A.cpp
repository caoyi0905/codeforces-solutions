#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--){
        int x,y;string op;
        cin>>x>>op>>y;
        if(op=="!="){
            puts(x!=y?"true":"false");
        }else if(op=="=="){
            puts(x==y?"true":"false");
        }else if(op=="<"){
            puts(x<y?"true":"false");
        }else if(op=="<="){
            puts(x<=y?"true":"false");
        }else if(op==">"){
            puts(x>y?"true":"false");
        }else puts(x>=y?"true":"false");
    }
}
