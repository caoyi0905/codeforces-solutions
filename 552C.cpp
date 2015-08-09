#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,w,m;
    cin>>w>>m;
    if(w<=3) return puts("YES");
    while(m){
        int x=m%w;
        if(x<=1) m/=w;
        else if(x==w-1) m=m/w+1;
        else return puts("NO");
    }
    puts("YES");
}
