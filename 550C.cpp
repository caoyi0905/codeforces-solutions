#include<bits/stdc++.h>
using namespace std;
bool gao(string s)
{
    int i,j,k,n=s.size();
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                int x=(s[i]-'0')*100+(s[j]-'0')*10+s[k]-'0';
                if(x%8==0){
                    cout<<"YES"<<endl<<x<<endl;
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main()
{
    string s;
    cin>>s;s="00"+s;
    if(gao(s)) puts("NO");
}
