#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int len1=1,len2=1;
    for(i=7;i<n;i*=7) len1++;
    for(i=7;i<m;i*=7) len2++;
    int ans=0;
    if(len1+len2<=7)
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                vector<int> used(7,0);
                for(int a=i,k=0;k<len1;a/=7,k++)
                    used[a%7]+=1;
                for(int b=j,k=0;k<len2;b/=7,k++)
                    used[b%7]+=1;
                if(*max_element(used.begin(),used.end())<=1) ans++;
            }
    cout<<ans<<endl;
}
