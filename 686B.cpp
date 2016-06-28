#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
    int i,j,n;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=n;i>1;i--){
        for(j=0;j<i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                cout<<j<<' '<<j+1<<endl;
            }
        }
    }
}
