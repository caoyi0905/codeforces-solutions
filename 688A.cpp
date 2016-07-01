#include<bits/stdc++.h>
using namespace std;
char ch[101][101];
int main()
{
    int n,d,i,j,maxx=0,cnt=0;
    cin>>n>>d;
    for(i=1;i<=d;i++)
        cin>>ch[i]+1;
    for(i=1;i<=d;i++){
        for(j=1;j<=n;j++){
            if(ch[i][j]=='0') break;
        }
        if(j!=n+1){
            cnt++;
            maxx=max(maxx,cnt);
        }else cnt=0;
    }
    cout<<maxx;
}
