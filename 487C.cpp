#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int x){
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return 1;
    return 0;
}
ll pow_mod(ll a,ll b,ll M) {ll res=1;a%=M;for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res;}
int main()
{
    int n;
    cin>>n;
    if(n==1)
        return puts("YES\n1");
    if(n==4)
        return puts("YES\n1 3 2 4");
    if(check(n)) return puts("NO");
    puts("YES\n1");
    for(int i=2;i<=n;i++){
        printf("%I64d\n",((1LL*i*pow_mod(i-1,n-2,n)-1)%n+1));
    }
}
