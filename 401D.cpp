#include<bits/stdc++.h>
using namespace std;
long long dp[1<<18][110];
bool mark[1<<18][110][10];
int main()
{
    int m,n;
    string s;
	cin>>s>>m;
	n=s.size();
	sort(s.begin(),s.end());
	dp[0][0]=1;
	mark[0][0][0]=1;
	for(int i=0;i<1<<n;++i)
		for(int j=0;j<m;++j)
			if(dp[i][j])
				for(int k=0;k<n;++k)
					if(!(i&(1<<k))&&!mark[i][j][s[k]-'0']){
						dp[i|(1<<k)][(j*10+s[k]-'0')%m]+=dp[i][j];
						mark[i][j][s[k]-'0']=1;
					}
	cout<<dp[(1<<n)-1][0]<<endl;
	return 0;
}
