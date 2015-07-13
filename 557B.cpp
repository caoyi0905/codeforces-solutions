#include<bits/stdc++.h>
using namespace std;
int a[211111];
int main()
{
    int i,n;double w;
    cin>>n>>w;
    for(i=1;i<=2*n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n*2+1);
    printf("%.6lf\n", min(min(2*a[1], a[n+1])*1.5*n,w));
}
