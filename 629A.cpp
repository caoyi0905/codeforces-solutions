#include<bits/stdc++.h>
using namespace std;
char ch[101][101];
int main()
{
    int i,j,n,ans=0;
    cin>>n;
    for(i=0;i<n;i++) cin>>ch[i];
    for(i=0;i<n;i++){
        int cnt=0,cnt2=0;
        for(j=0;j<n;j++){
            if(ch[i][j]=='C') cnt++;
            if(ch[j][i]=='C') cnt2++;
        }
        ans+=cnt*(cnt-1)/2;
        ans+=cnt2*(cnt2-1)/2;
    }
    cout<<ans<<endl;
}
