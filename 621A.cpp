#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;

int main()
{
    ll sum=0;
    int x,i,n,minj=INT_MAX;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        sum+=x;
        if(x%2){
            minj=min(minj,x);
        }
    }
    if(sum%2==0) cout<<sum;
    else{
        cout<<sum-minj;
    }
}
