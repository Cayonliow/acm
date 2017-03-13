#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int c[33000];

int lowbit(int x)
{
	return x&(-x);
}

int sum(int x)
{
	int r=0;
	while(x>0)
	{
		r=r+c[x];
		x=x-lowbit(x);
	}
	
	return r;
}

void add(int x)
{
	while(x<33000)
	{
		c[x]++;
		x=x+lowbit(x);
	}
	
}

int main()
{
	int number;	
	while(scanf("%d",&number)==1)
	{
		int x,y;
		int l[33000]={0};
		
		memset(c,0,sizeof(c));
		for(int i=0;i<number;i++)
		{
			scanf("%d %d",&x,&y);
			x++;
			l[sum(x)]++;
			add(x);
		}	
		
		for(int i=0;i<number;i++)
		{
			printf("%d\n",l[i]);
		}
	}	
}



/*int main()
{
	for(int i=0;i<=32000;i++)
	{
		if(lowbit(i)!=1)
		printf("%d = %d\n",i,lowbit(i));
	}
	
 }*/ 
