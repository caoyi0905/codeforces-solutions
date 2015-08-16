#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll pow_mod(ll a,ll b,ll M) {ll res=1;a%=M;for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res;}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    if (k>n||k==1) printf("%d\n",pow_mod(m,n,mod));
    else if (k==n) printf("%d\n",pow_mod(m,(k+1)/2,mod));
    else if (k%2) printf("%d\n",m*m);
    else printf("%d\n",m);
}
