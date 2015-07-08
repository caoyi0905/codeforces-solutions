#include<bits/stdc++.h>
using namespace std;
const int maxx=1001;
const double eps=1e-7;
int n,m,pre[maxx];
double a[maxx],b[maxx],c[maxx],dp[maxx];
bool check(double x){
    for(int i=1;i<=n;i++) c[i]=x*b[i];
    for(int i=1;i<=n;i++){
        dp[i]=-1e60;
        for(int j=0;j<i;j++){
            if(dp[i]<dp[j]+c[i]-sqrt(fabs(a[i]-a[j]-m))){
                dp[i]=dp[j]+c[i]-sqrt(fabs(a[i]-a[j]-m));
                pre[i]=j;
            }
        }
    }
    return dp[n]>-eps;
}
vector<int> ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    double l=0,r=1000;
    while(l+eps<r){
        double mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    for(int i=n;i;i=pre[i]) ans.push_back(i);
    for(int i=ans.size()-1;~i;i--) printf("%d ",ans[i]);
}
