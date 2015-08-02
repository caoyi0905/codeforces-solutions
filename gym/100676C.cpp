#include<bits/stdc++.h>
using namespace std;
int a[111];
bool cmp(int a,int b){return a>b;}
int main()
{
    int T,i;
    cin>>T;
    while(T--){
        int k,m,n,sum=0;
        cin>>k>>m>>n;
        for(i=1;i<=n;i++) cin>>a[i],sum+=a[i];
        sort(a+1,a+n+1,cmp);
        for(i=1;i<=n;i++){
            sum-=a[i];
            if(sum+m<=k) break;
        }
        cout<<i<<endl;
    }
}
