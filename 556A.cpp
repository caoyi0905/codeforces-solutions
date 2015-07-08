#include<bits/stdc++.h>
using namespace std;
stack<char> st;
int main()
{
    int i,n;
    char s;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>s;
        if(st.empty()){
            st.push(s);
            continue;
        }
        char r=st.top();
        if(r!=s){
            st.pop();
        }else{
            st.push(s);
        }
    }
    cout<<st.size();
}
