#include<iostream>
#include<cstdio>

using namespace std;

int lis[1001]={0};

void LIS(int f[],int n)
{
	//lis[0]=1;
	for(int i=0;i<=n;i++)
	{
		lis[i]=1;
		for(int j=0;j<i;j++)
		{
			if(f[j]<f[i]&&lis[j]+1>lis[i])
			{
				lis[i]=lis[j]+1;
			}
		}
	}
}

int Longest(int n)
{
	for(int i=n;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			if(lis[j]==i)
			{
			//	printf("%d",i+1);
				return i;
			}
		}
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		int f[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&f[i]);
		}
		
		LIS(f,n);
		printf("%d",Longest(n));
		
		
	}
}
