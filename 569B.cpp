#include<bits/stdc++.h>
using namespace std;
int a[111111];
set<int> st,st2;
int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++) st2.insert(i);
    for(i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>n||st.count(a[i])) a[i]=0;
        else st2.erase(a[i]),st.insert(a[i]);
    }
    auto it=st2.begin();
    for(i=1;i<=n;i++){
        if(a[i]==0){
            cout<<*it<<' ';
            it++;
        }else cout<<a[i]<<' ';
    }
}
