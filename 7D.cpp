#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int dp[5111111];
char str[5111111];
int main()
{
    ll l=0,r=0,ans=0,k=1;
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        l=l*31+str[i]-'a';
        r=r+(str[i]-'a')*k;
        k*=31;
        if(l==r) dp[i+1]=dp[(i+1)/2]+1;
        ans+=dp[i+1];
    }
    cout<<ans<<endl;
}
