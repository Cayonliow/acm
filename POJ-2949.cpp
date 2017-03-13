#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
struct Node
{
	int X,Y;
	double L;
}A[300010];

char S[10010];
int number;

int spfa(double middle)
{
	double dis[1000];
	int flag;
	int x,y;
	double l;
	
	for(int i=0;i<1000;i++)
	{
		dis[i]=-1e10;
	} 
	
	for(int i=0;i<=680;i++)
	{
		flag=0;
		
		for(int j=0;j<number;j++)
		{
			x=A[j].X;
			y=A[j].Y;
			l=A[j].L-middle;
			if(dis[x]+l>dis[y])
			{
				dis[y]=dis[x]+l;
				flag=1;
			} 
		}
		if(flag==0)
		{
			break;
		} 
	}
	
	return flag;
}

int main()
{
	int x,y,l;
	double Min,Max,Mid;

	while(scanf("%d",&number)&&number!=0)
	{
		Min=1e10;
		Max=0.0;
		for(int i=0;i<number;i++)
		{
			scanf("%s",S);
			
			x=(S[0]-'a')*26+S[1]-'a';
			y=(S[strlen(S)-2]-'a')*26+S[strlen(S)-1]-'a';
			
			A[i].X=x;
			A[i].Y=y;
			A[i].L=(double)strlen(S);
			
			if(Min>A[i].L)
			{
				Min=A[i].L;
			}
			
			if(Max<A[i].L)
			{
				Max=A[i].L;
			}
		}
		
		Min=0.00;
		
		while(Max-Min>0.001)
		{
			Mid=(Min+Max)/2;
			if(spfa(Mid))
			{
				Min=Mid;
			} 
			else
			{
				Max=Mid;
			} 
		}
		
		if(Min>0.001)
		{
			printf("%.2lf\n",Min);
		}
			
		else
		{
			printf("No solution.\n");
		}
	}
	return 0;
}
