#include<bits/stdc++.h>
using namespace std;
int main()
{
    string un[20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    string t[8]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    int x;
    cin>>x;
    if(x<=19)
        cout<<un[x];
    else
    {
        int d = x%10;
        x/=10;
        cout<<t[x-2];
        if(d!=0) cout<<"-"<<un[d];
    }
    return 0;
}
