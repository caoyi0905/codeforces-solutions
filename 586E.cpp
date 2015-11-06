#include<bits/stdc++.h>
using namespace std;
vector<long long> ans;
int main()
{
    int x,y;
    char ta='A',tb='B';
    if(x<y){
        swap(x,y);swap(ta,tb);
    }
    if(gcd(x,y)!=1) puts("Impossible");

}
