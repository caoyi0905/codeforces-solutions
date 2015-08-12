#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,a,b,t;
    cin>>a>>b>>n;
    set<int> s;
    t=__gcd(a,b);
    for(int i=1;i*i<=t;i++){
        if(t%i==0){
            s.insert(-i);
            s.insert(-t/i);
        }
    }
    while(n--){
        int low,high;
        cin>>low>>high;
        auto t=s.lower_bound(-high);
        if(t==s.end()) puts("-1");
        else if((*t)<=-low) printf("%d\n",-*t);
        else puts("-1");
    }
}
