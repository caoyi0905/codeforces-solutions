#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool jud(int x){

}
int main()
{
    int a,b,n,i,l,r,ans;
    cin>>a>>b>>n;
    for(i=1;i<=n;i++){
        cin>>l>>t>>m;
        r=n;ans=-1;
        while(l<=r){
            int mid=l+r>>1;
            if(jud(mid)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        cout<<ans<<endl;
    }
}
