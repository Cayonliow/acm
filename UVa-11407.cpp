#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int N;
	int a[10010];
	int dp[10010];
	
	for(int i=1;i<=10010;i++)
	{
		dp[i]=i;
	}
	
	for(int i=1;i*i<10010;i++)
	{
		dp[i*i]=1;
	}
	
	for(int i=1;i<10010;i++)
	{
		for(int j=1;j<=i/2;j++)
		{
			//printf("i=%d j=%d dp[i]=%d dp[j]=%d dp[i-j]=%d dp[j]+dp[i-j]=%d\n",i,j,dp[i],dp[j],dp[i-j],dp[j]+dp[i-j]);
			dp[i]=min(dp[i],dp[j]+dp[i-j]);
			//(dp[i]<dp[j]+dp[i-j])?dp[i]:dp[j]+dp[i-j];
		}
	}
	
	while(scanf("%d",&N)!=EOF)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<N;++i)
		{
			scanf("%d",&a[i]);
			//printf("dp[i]=%d dp[i*i]=%d\n",dp[a[i]],dp[a[i]*a[i]]);	
		}
		
		
		for(int i=0;i<N;++i)
		{
			printf("%d\n",dp[a[i]]);
		}
	}
}
