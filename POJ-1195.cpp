#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int AAA[2000][2000];
int BBB[2000][2000];
int number;

int lowbit(int x)
{
	return x&(-x);
}

void update(int x,int y,int a)
{
	for(int i=x;i<=number;i=i+lowbit(i))
	{
		for(int j=y;j<=number;j=j+lowbit(j))
		{
			BBB[i][j]=BBB[i][j]+a;
		}
	}
}

int Sum(int x,int y)
{
	int sum=0;
	for(int i=x;i>0;i=i-lowbit(i))
	{
		for(int j=y;j>0;j=j-lowbit(j))
		{
			sum=sum+BBB[i][j];
		}
	}
	
	return sum;
}

int main()
{
	int zero,x,y,a,l,b,r,t,I;
	scanf("%d%d",&zero,&number);

	number++;	
		
		memset(AAA,0,sizeof(AAA));
		memset(BBB,0,sizeof(BBB));
	
		while(scanf("%d",&I) &&I!=3)
		{
			if(I==1)
			{
				scanf("%d%d %d",&x,&y,&a);
				x++;y++;
				update(x,y,a);
			}
			
			if(I==2)
			{
				scanf("%d%d%d%d",&l,&b,&r,&t);
				l++;b++;r++;t++;
				int answer=Sum(r,t)-Sum(l-1,t)-Sum(r,b-1)+Sum(l-1,b-1);
				//printf("%d %d %d %d",Sum(r,t),Sum(l-1,t),Sum(r,b-1),Sum(l-1,b-1));
				printf("%d\n",answer); 
			}
		}
	
	
}
