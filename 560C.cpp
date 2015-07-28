#include<bits/stdc++.h>
int s[7];
using namespace std;
int main()
{
    for(int i=1;i<=6;i++) cin>>s[i];
    int a=(s[1]+s[2]+s[3]);
    printf("%d\n",a*a-s[1]*s[1]-s[3]*s[3]-s[5]*s[5]);
  return 0;
}
