#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main()
{
    int x,sum=0,t=0;
    for(int i=0;i<5;i++){
        cin>>x;
        sum+=x;
        mp[x]++;
    }
    for(auto it:mp){
        if(it.second>1){
            t=max(t,it.first*min(3,it.second));
        }
    }
    cout<<sum-t;
}

