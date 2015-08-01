#include<bits/stdc++.h>
using namespace std;
set<int> st;
int main()
{
    int T;
    cin>>T;
    while(T--){
        int i,n,k,x,ans=999999999;
        cin>>n>>k;
        st.clear();
        for(i=1;i<=n;i++){
            cin>>x;
            if(x==0) continue;
            if(k%x==0&&st.count(k/x)){
                ans=min(ans,min(k/x,x));
            }
            st.insert(x);
        }
        if(ans==999999999){
            cout<<-1<<endl;
        }else{
            cout<<ans<<' '<<k/ans<<endl;
        }
    }
}
