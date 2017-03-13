#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;	
int s[14]={0};
int ss[14]={1};
int p[14]={-1};
int k;
void backtracking(int dimension)
{

	if(dimension==6)
	{
		for(int i=0;i<5;i++)
		{
			printf("%d ",p[i]);
			/*if(i!=5)
			{
				printf(" ");
			} 
			else
			{
				printf("\n");
			}*/		
		}
		printf("%d\n",p[5]);
	return;
	}
	
	for(int i=0;i<k;i++)
	{
		if(ss[i]==0)
		{
			
			if(s[i]>p[dimension-1])
			{
				ss[i]=1;
				p[dimension]=s[i];
				backtracking(dimension+1);
				ss[i]=0;
			}
		}
	}
}

int main()
{
	//int k;
	int count=0;
	//int y[14]={0};

	while(scanf("%d",&k)==1&&k!=0)
	{
		for(int i=0;i<k;i++)
		{
			scanf("%d",&s[i]);
			ss[i]=0;
		}
		if(count++)printf("\n");
		sort(s,s+k);
		backtracking(0);
			
		
	}

}
