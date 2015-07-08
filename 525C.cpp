#include<bits/stdc++.h>
#define maxx 111111
using namespace std;
long long l[maxx];
bool cmp(long long a,long long b){return a>b;}
int main(){
    int i,n;long long w=0,h=0;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>l[i];
    sort(l+1,l+1+n,cmp);
    long long ans=0;
    for(i=1;i<n;i++){
        if(w==0){
            if(l[i]-l[i+1]<=1){
                w=l[i+1];i++;
            }
        }else{
            if(l[i]-l[i+1]<=1){
                h=l[i+1];ans+=h*w;
                h=w=0;
                i++;
            }
        }
            }
    cout<<ans;
}
