#include<iostream>
#include<cstdio>

using namespace std;

int lis[100001]={0};

int LIS(int f[],int n)
{
	int max=0;
	//lis[0]=1;
	for(int i=n-1;i>=0;--i)
	{
		lis[i]=1;
		for(int j=n-1;j>i;--j)
		{
			if(f[j]<f[i]&&lis[j]+1>lis[i])
			{
				lis[i]=lis[j]+1;
			}
		}
	
	
	if(lis[i]>max)
	{
		max=lis[i];
	}
	}
	return max;
	
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
	int Case=1;
	while(1)
	{
		int num;
		
		scanf("%d",&num);
		if(num==-1)
		{
			return 0;
		} 
	
		int a[100000];
		a[0]=num;
		int count =1;
		while(scanf("%d",&a[count]) && a[count]!=-1)
		{
			count++;
		}
		
		
		if(Case!=1)
		{
			printf("\n");
		}
	    printf("Test #%d:\n", Case++);
        printf("  maximum possible interceptions: %d\n", LIS(a,count));	
		
		
		
		
		
		
		
	}
	
}
