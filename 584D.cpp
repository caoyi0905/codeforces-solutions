#include<bits/stdc++.h>
using namespace std;
int check(int x)
{
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++) if(x%i==0)return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    if(check(n)) printf("1\n%d",n);
    else if(n==4) printf("2\n2 2");
    else{
        int a=n-2,b;
        while(!check(a)) a--;
        n-=a;
        if(check(n)){
            puts("2");
            cout<<a<<' '<<n<<endl;
            return 0;
        }
        cout<<3<<endl;
        for(b=2;;b++) if(check(b)&&check(n-b)){
            cout<<a<<' '<<b<<' '<<n-b<<endl;
            break;
        }
    }
}
