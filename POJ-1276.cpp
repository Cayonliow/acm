#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

struct bag
{
	int n;
	int D;	
};

int main()
{
	int cash;
	while(scanf("%d",&cash)!=EOF)
	{
		int place=0;
		int N;
		scanf("%d",&N);
		
		bag arr[100050];
		int deno[100050];
		memset(deno,0,sizeof(deno));
		
		for(int i=0;i<N;i++)
		{
			scanf("%d",&arr[i].n);
			scanf("%d",&arr[i].D);
			//printf("ccc%d",arr[i].n);
			//printf("ccc%d",arr[i].D);
			
			int temp=1;
			while(arr[i].n>=temp)
			{
				deno[++place]=arr[i].D*temp;
				arr[i].n=arr[i].n-temp;
				temp=temp*2;
				//place++;
				
			}
			if(arr[i].n!=0)
			{
				deno[++place]=arr[i].D*arr[i].n;
				//place++;
			}
		}
		
		int dp[100050];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<=place;i++)
		{
			for(int j=cash;j>=0;j--)
			{
				dp[j]=dp[j];
				if(j-deno[i]>=0)
					dp[j]=dp[j]+dp[j-deno[i]];
			}
		}
		
		for(int i=cash;i>=0;--i)
		{
			if(dp[i])
			{
				printf("%d\n",i);
				break;
			}
		}
		
	}
}
