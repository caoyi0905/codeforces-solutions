#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b,c,d;
    cin>>n>>m>>a>>b>>c>>d;
    if(((a+c)<=n&&max(b,d)<=m)||((a+c)<=m &&max(b,d)<=n)||
    ((a+d)<=n &&max(b,c)<=m)||((a+d)<=m &&max(b,c)<=n)||
    ((b+d)<=n &&max(a,c)<=m)||((b+d)<=m &&max(a,c)<=n)||
    ((b+c)<=n &&max(a,d)<=m)||((b+c)<=m &&max(a,d)<=n))
        printf("YES\n");
    else
        printf("NO\n");
}
