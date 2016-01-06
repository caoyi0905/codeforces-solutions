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
template<typename __ll>
inline void R(__ll &m){
    __ll x=0,f=1;char ch=getchar();
    while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    m=x*f;
}
int n,p[100001],x,i;
int main()
{
    R(n);
    for(i=1;i<=n;i++) R(x),p[x]=i;
    int cur=1,ans=1;
    for(i=2;i<=n;i++){
        if(p[i]>p[i-1]) cur++;
        else cur=1;
        ans=max(ans,cur);
    }
    cout<<n-ans;
}
