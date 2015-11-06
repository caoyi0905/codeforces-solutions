#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    ll v,d,p,id;
}a[4111];
int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i].v>>a[i].d>>a[i].p;
    vector<int> ans;
    for(i=1;i<=n;i++)
    {
        if(a[i].p>=0)
        {
            ll tmp=0;
            ans.push_back(i);
            for(int j=i+1;j<=n;j++){
                if(a[j].p>=0){
                    a[j].p-=a[i].v+tmp;
                    if(a[j].p<0) tmp+=a[j].d;
                    if(a[i].v) a[i].v--;
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans) cout<<it<<' ';
}
