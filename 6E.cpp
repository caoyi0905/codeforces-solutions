#include<bits/stdc++.h>
#define maxx 100001
using namespace std;
int n,a[maxx],mn[maxx][19],mx[maxx][19];
void pre()
{
	for(int i=1;i<=n;i++)
	   mx[i][0]=mn[i][0]=a[i];
	int t=log(n)/log(2);
    for(int i=1;i<=t;i++)
       for(int j=n;j>0;j--)
       {
       	   mx[j][i]=mx[j][i-1];
       	   if(j+(1<<(i-1))<=n)
       	   mx[j][i]=max(mx[j][i],mx[j+(1<<(i-1))][i-1]);
       }
    for(int i=1;i<=t;i++)
       for(int j=n;j>0;j--)
       {
       	   mn[j][i]=mn[j][i-1];
       	   if(j+(1<<(i-1))<=n)
       	   mn[j][i]=min(mn[j][i],mn[j+(1<<(i-1))][i-1]);
       }
}
int rmq(int l,int r)
{
    int m=log(r-l+1)/log(2);
    int a=max(mx[l][m],mx[r-(1<<m)+1][m]);
    int b=min(mn[l][m],mn[r-(1<<m)+1][m]);
    return a-b;
}
vector<pair<int,int> > ans;
int main()
{
    int i,j,k,len=0;
    cin>>n>>k;
    for(i=1;i<=n;i++) cin>>a[i];
    i=j=1;
    pre();
    while(i<=n&&j<=n){
        int cha=rmq(i,j);
        while(cha<=k&&j<=n){
            len=max(len,j-i+1);
            j++;
            cha=rmq(i,j);
        }
        i++;
    }
    i=j=1;
    while(i<=n&&j<=n){
        int cha=rmq(i,j);
        while(cha<=k&&j<=n){
            if(j-i+1==len) ans.push_back(make_pair(i,j));
            j++;
            cha=rmq(i,j);
        }
        i++;
    }
    cout<<len<<' '<<ans.size()<<endl;
    for(i=0;i<ans.size();i++){
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
}
