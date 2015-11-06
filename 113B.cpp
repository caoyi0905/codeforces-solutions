#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int MAXN = 100010,MAXM = 100010;
char T[MAXN],P[MAXM];
int Next[MAXM],N,M,C;
int a[MAXN],b[MAXN],flag[MAXN];
string t,s1,s2;
void MakeNext(string &t)
{
    int i=0,j=-1;
    Next[i]=-1;
    while(i<t.size()){
        if(j==-1||t[i]==t[j])Next[++i]=++j;
        else j=Next[j];
    }
}
int KMP(string &p,string &t,int Ans[])
{
    int i=0,j=0,ans=0;
    while(i<p.size()){
        if(p[i]==t[j]||j==-1)i++,j++;
        else j=Next[j];
        if(j==t.size()){
            Ans[++ans]=i-j;
            j=Next[j-1];
            i--;
        }
    }
    return ans;
}
vector<ll> ans;
void hash_get(int x)
{
    ll seed=131; // 31 131 1313 13131 131313 etc..
    ll Hash=0;
    for(int i=x;i<t.size();i++){
        Hash=Hash*seed+t[i];
        if(flag[i]&&i-x+1>=max(s1.size(),s2.size())){
            ans.push_back(Hash);
        }
    }
}
int main()
{
    cin>>t>>s1>>s2;
    int i,j;
    MakeNext(s1);
    int len=KMP(t,s1,a);
    MakeNext(s2);
    int len2=KMP(t,s2,b);
    for(int i=1;i<=len2;i++) flag[b[i]+s2.size()-1]=i;
    i=0;
    while(s1.size()-1-i>=0&&i<s2.size()&&s1[s1.size()-1-i]==s2[i]) i++;
    int len3=max((int)s1.size()-i,1);
    int l=1;
    for(i=1;i<=len;i++){
        hash_get(a[i]);
    }
    sort(ans.begin(),ans.end());
    cout<<std::unique(ans.begin(),ans.end())-ans.begin();
}
