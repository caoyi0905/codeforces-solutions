#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<=2)
        cout<<-1<<endl;
    else
    {
        cout<<35<<endl;
        cout<<77<<endl;
        for(int i=1;i<=n-2;i++)
            cout<<55*i<<endl;
    }
    return 0;
}
