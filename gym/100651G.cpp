#include<bits/stdc++.h>
using namespace std;
char a[22][22];
int main()
{
    int i,j,n;string s;
    while(cin>>n&&n){
        cin>>s;
        memset(a,0,sizeof a);
        int len=s.length()/n,t=0;
        for(i=0;i<len;i++){
            if(i%2==0){
                for(j=0;j<n;j++) a[i][j]=s[t++];
            }else{
                for(j=n-1;j>=0;j--) a[i][j]=s[t++];
            }
        }
        for(j=0;j<n;j++)
            for(i=0;i<len;i++) cout<<a[i][j];
        cout<<endl;
    }
}
