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
int r[111111],l[111111];
int main()
{
    int i,n,p;
    double sum=0;
    cin>>n>>p;
    for(i=1;i<=n;i++)  cin>>l[i]>>r[i];
    l[n+1]=l[1];r[n+1]=r[1];
    for(i=1;i<=n;i++){
        double pa=1.*(r[i]/p-(l[i]-1)/p)/(r[i]-l[i]+1);
        double pb=1.*(r[i+1]/p-(l[i+1]-1)/p)/(r[i+1]-l[i+1]+1);
        sum+=1-(1-pa)*(1-pb);
    }
    sum*=2000;
    printf("%.6f",sum);
}
