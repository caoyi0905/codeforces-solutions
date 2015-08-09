#include<bits/stdc++.h>
using namespace std;
int dp[1111];
int main()
{
    int i,k,n,T;
    string s;
    cin>>T;
    while(T--){
        cin>>n>>k>>s;
        dp[n]=0;
        for(i=n-1;i>=0;i--){
            bool isAlter=true;
            dp[i]=1e9;
            for(int j=i;j-i+1<=k&&j<s.size();j++){
                if(j>i&&s[j]==s[j-1]) isAlter=false;
                if(i==j||isAlter==false)
                    dp[i]=min(dp[i],dp[j+1]+1);
            }
        }
        cout<<dp[0]-1<<endl;
    }
}
