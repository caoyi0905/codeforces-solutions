#include<bits/stdc++.h>
using namespace std;
int s[1001];
int main()
{
    int i,n,m,h,sum=0;
    cin>>n>>m>>h;
    for(i=1;i<=m;i++){
        cin>>s[i];sum+=s[i];
    }
    if(sum<n) return puts("-1");
    sum--;n--;s[h]--;
    double ans=1;
    for(int i=0;i<s[h];i++) ans*=1.*(sum-n-i)/(sum-i);
    printf("%.9f",1-ans);
}
