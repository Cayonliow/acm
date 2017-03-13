#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int N,Q,check;
	
	
	scanf("%d",&N) ;
	
		int female[N];
		memset(female,0,sizeof(female));
		for(int i=0;i<N;i++)
		{
			scanf("%d",&female[i]);
		}
	
		scanf("%d",&Q);

		for(int i=0;i<Q;i++)
		{
			scanf("%d",&check);
			
			int *p=lower_bound(female,female+N,check);
			int *q=upper_bound(female,female+N,check);
			p--;
			if(p==female+N||p-female<0)
			{
				printf("X %d\n",female[q-female]);
			}
			
			else if(q==female+N)
			{
				printf("%d X\n",female[p-female]);
			}
			
			else
				printf("%d %d\n",female[p-female],female[q-female]);
		}
	

	

	
} 
