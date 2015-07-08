#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int main()
{
    int i,j,ans=0;
    string n;
    cin>>n;
    for(i=0;i<n.size();i++){
        ans=max(ans,n[i]-'0');
        for(j=0;j<n[i]-'0';j++){
            a[j][i]=1;
        }
    }
    cout<<ans<<endl;
    for(i=0;i<ans;i++){
        for(j=0;!a[i][j];j++);
        for(;j<n.size();j++)
            cout<<a[i][j];
        cout<<' ';
    }
}
