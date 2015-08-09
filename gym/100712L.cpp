#include<bits/stdc++.h>
using namespace std;
const int Maxn=100020;
int dp[Maxn],q[Maxn];
char s[Maxn];
int n,k,l[Maxn];
int main()
{
	int _;scanf("%d",&_);
	while(_--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		dp[0]=0;
		l[0]=l[1]=-1;
		for(int i=2;i<=n;i++)
			if(s[i]==s[i-1])l[i]=i-2;
			else
			{
				l[i]=l[i-1];
			}
		int front=0,rear=0;
		q[rear++]=0;
		for(int i=1;i<=n;i++)
		{
			dp[i]=dp[i-1]+1;
			if(front<rear&&q[front]<i-k)front++;
			if(front<rear&&q[front]<=l[i])
				dp[i]=min(dp[i],dp[q[front]]+1);
			while(front<rear&&dp[q[rear-1]]>dp[i])
			{
				rear--;
			}
			q[rear++]=i;
		}
		printf("%d\n",dp[n]-1);
	}
}
