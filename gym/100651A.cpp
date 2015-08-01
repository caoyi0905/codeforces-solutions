#include<bits/stdc++.h>
using namespace std;
long long dp[11111];
int main()
{
    int i;
    char s[11111];
    while(scanf("%s",s+1)){
        if(s[1]=='0') break;
        int len=strlen(s+1);
        dp[0]=1;
        for(i=1;i<=len;i++){
            if(s[i]=='0') dp[i]=dp[i-2];
            else if(i>1&&s[i-1]-'0'>=1&&s[i-1]-'0'<=2&&(s[i-1]-'0')*10+s[i]-'0'<=26) dp[i]=dp[i-2]+dp[i-1];
            else dp[i]=dp[i-1];
        }
        cout<<dp[len]<<endl;
    }
}
