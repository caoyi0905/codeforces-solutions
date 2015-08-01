#include<bits/stdc++.h>
using namespace std;
int a[11],n,s,ans;
void dfs(int id,int sum,int minn,int cnt){
    if(sum>=s&&sum-minn<s){
        ans=max(ans,cnt);
        return ;
    }
    for(int i=id+1;i<=n;i++){
        dfs(i,sum+a[i],min(minn,a[i]),cnt+1);
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        int i;
        ans=0;
        cin>>n>>s;
        for(i=1;i<=n;i++) cin>>a[i];
        dfs(0,0,9999,0);
        cout<<ans<<endl;
    }
}
