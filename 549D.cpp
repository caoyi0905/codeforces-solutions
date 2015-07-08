#include<bits/stdc++.h>
using namespace std;
char ch[111][111];
int s[111][111];
int aa[111],bb[111];
int a,b,c;
int main()
{
    int i,j,n,m;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>ch[i]+1;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(j>1&&ch[i][j]!=ch[i][j-1]&&!s[i][j-1]&&!aa[j-1]){
                aa[j-1]=1;
                s[i][j-1]=1;
                a++;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(i>1&&ch[i][j]!=ch[i-1][j]&&!s[i-1][j]&&!bb[i-1]){
                bb[i-1]=1;
                s[i-1][j]=1;
                b++;
            }
        }
    }
    for(i=2;i<=n;i++){
        for(j=2;j<=m;j++){
            if(ch[i][j]!=ch[i][j-1]&&ch[i][j]!=ch[i-1][j]&&ch[i][j]!=ch[i-1][j-1]){
                c++;
            }
        }
    }
    cout<<a+b+c+1<<endl;
}
