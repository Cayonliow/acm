#include<iostream>
#include<cstdio>
#include<cstring>


using namespace std;

int Distance[110][110];
const int inf=0x3f3f3f3f;

int main()
{
	int set;
	while(scanf("%d",&set)&&set!=0)
	{
		for(int i=0;i<set;i++)
		{
			for(int j=0;j<set;j++)
			{
				Distance[i][j]=inf;
			}
		} 
	
		int n;
		int other;	
		for(int i=0;i<set;i++)
		{
			scanf("%d",&n);
			
			for(int j=0;j<n;j++)
			{
				scanf("%d",&other);
				scanf("%d",&Distance[i][other-1]);
			}
		}
		
		//Floyd
		for(int i=0;i<set;i++)
		{
			for(int j=0;j<set;j++)
			{
				for(int k=0;k<set;k++)
				{
					if((Distance[j][i]+Distance[i][k])<Distance[j][k])
					{
						Distance[j][k]=Distance[j][i]+Distance[i][k];
					}
					
					else
					{
						Distance[j][k]=Distance[j][k];
					}
				}
			}
		}
		
		int ww=-1;
		int time=inf;
		
		for(int i=0;i<set;i++)
		{
			int tmp=-1;
			for(int j=0;j<set;j++)
			{
				if(i==j)	continue;
			
				if(tmp<=Distance[i][j])
				{
					tmp=Distance[i][j];
				}
			}
			
			if(time>tmp)
			{
				time=tmp;
				ww=i+1;
			}
			
		}
		
		if(inf==time)
		{
			printf("disjoint\n");
		}
		
		else
		{
			printf("%d %d\n",ww,time);	
		}		
	}
	
}
