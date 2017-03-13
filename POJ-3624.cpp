#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int c[450];
int N,M;
int w[4000];
int d[4000];


int knapsack(int N,int M)
{
	memset(c,0,sizeof(c));
	for(int i=0;i<N;i++)
	{
		for(int j=M;j-w[i]>=0;j--)
		{
			c[j]=max(c[j],c[j-w[i]]+d[i]);
		}
	}
	
	sort(c,c+M+1);
	return c[M];
}




int main()
{
	
	while(scanf("%d %d",&N,&M)==2)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d %d",&w[j],&d[j]);
		}
	
		printf("%d",knapsack(N,M));
	
	
	}
}
