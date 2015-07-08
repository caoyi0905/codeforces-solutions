#include<bits/stdc++.h>
using namespace std;
int a[1111];
int main()
{
    int i,n,k,p,x,y,sum=0,cnt=0;
    cin>>n>>k>>p>>x>>y;
    for(i=1;i<=k;i++) cin>>a[i],sum+=a[i];
    if(sum+n-k>x){return puts("-1");}
    sort(a+1,a+1+k);
    for(i=1;i<=k;i++)
        if(a[i]<y) cnt++;
    if(k<=n/2){
        sum+=(n/2-cnt)+y*(n/2-k+1+cnt);
        if(sum>x){return puts("-1");}
        for(i=1;i<=n/2-cnt;i++) printf("%d ",1);
        for(i=1;i<=n/2-k+1+cnt;i++) printf("%d ",y);
        return 0;
    }
    if(cnt>n/2){return puts("-1");}
    vector<int> ans;
    for(i=1;i<=min(n-k,n/2-cnt);i++) ans.push_back(1);
    sum+=min(n-k,n/2-cnt);int left=n-k-min(n-k,n/2-cnt);
    for(i=1;i<=left;i++) ans.push_back(y);
    sum+=left*y;
    if(sum>x){return puts("-1");}
    for(i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
}
