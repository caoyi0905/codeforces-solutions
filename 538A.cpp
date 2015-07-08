#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size()+1;j++){
            if(s.substr(0,i)+s.substr(j)=="CODEFORCES"){
                return puts("YES");
            }
        }
    }
    puts("NO");
}
