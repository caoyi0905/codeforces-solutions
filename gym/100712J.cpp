#include<bits/stdc++.h>
using namespace std;
map<int,int> mp1,mp2;
int main()
{
    int T;
    cin>>T;
    while(T--){
        int i,j,n,m,x;
        cin>>n>>m;
        mp1.clear();mp2.clear();
        for(i=1;i<=n;i++){
            cin>>x;
            mp1[x]++;
        }
        for(i=1;i<=m;i++){
            cin>>x;
            mp2[x]++;
        }
        auto it1=mp1.begin(),it2=mp2.begin();
        while(it1!=mp1.end()&&it2!=mp2.end()){
            while(it2!=mp2.end()&&it1->second>it2->second) mp2.erase(it2++);
            if(it2==mp2.end()) break;
            mp1.erase(it1++);
            mp2.erase(it2++);
        }
        puts(mp1.empty()?"YES":"NO");
    }
}
