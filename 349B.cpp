#include<bits/stdc++.h>
using namespace std;
int a[9];
int main()
{
    int i,v,m=111111;
    cin>>v;
    for(i=1;i<=9;i++){
        cin>>a[i];
        m=min(m,a[i]);
    }
    int d=v/m;
    if(d==0) return puts("-1");
    while(d--){
        for(int i=9;i;i--){
            if(v-a[i]>=d*m){
                cout<<i;
                v-=a[i];
                break;
            }
        }
    }
}
