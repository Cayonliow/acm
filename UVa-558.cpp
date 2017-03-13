#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n,m;
int U[2010];
int V[2010];
int W[2010];
int D[1010];

int bf()
{
	
	for(int i=0;i<n;i++)
	{
		D[i]=0x3f3f3f3f;	
	}
	
	D[0]=0;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int a=U[j];
			int b=V[j];
			
			if(D[a]+W[j]<D[b])
			{
				D[b]=D[a]+W[j];
			}
		}
		
	}
	
	for(int i=0;i<m;i++)
	{
		int c=U[i];
		int d=V[i];
		
		if(D[c]+W[i]<D[d])
		{
			return 0;
		}
	}
	
	return 1;
}




int main()
{
	int t;
	while(scanf("%d",&t)==1)
	{
		while(t--)
		{
			scanf("%d%d",&n,&m);
			
			for(int i=0;i<m;i++)
			{
				scanf("%d%d%d",&U[i],&V[i],&W[i]);
			}
			
			if(!bf())
			{
				printf("possible\n");
        	}
			else
			{
				printf("not possible\n");
			}
            
			
		}
	}
} 
