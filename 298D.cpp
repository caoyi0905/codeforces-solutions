#include<bits/stdc++.h>
#define maxx 111111
using namespace std;
int a[maxx],b[maxx];
bool cmp(int a,int b){return a>b;}
int main()
{
    int i,n,m,k;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=m;i++) scanf("%d",&b[i]);
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+m+1,cmp);
    for(i=1;i<=n;i++)
        if(a[i]>b[i]) return puts("YES");
    puts("NO");
}
