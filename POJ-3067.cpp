#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int Case;
	int n,m,k;
	while(scanf("%d",&Case)==1)
	{
		
		for(int g=0;g<Case;g++)
		{
			int count=0;
			scanf("%d %d %d",&n,&m,&k);
			int E[1000]={0};
			int W[1000]={0};
			for(int i=0;i<k;i++)
			{
				scanf("%d %d",&E[i],&W[i]);
			//}
		
		//	for(int i=0;i<k;i++)
		//	{
				for(int j=0;j<i;j++)
				{
					if(E[j]<E[i])
					{
						if(W[j]>W[i])
						{
							count++;
						}
					}
				
					else if(E[j]>E[i])
					{
						if(W[j]<W[i])
						{
							count++;
						}
					}
				}
			}
			
		printf("Test case %d: %d\n",g+1,count);
		
		}	
	}
}
