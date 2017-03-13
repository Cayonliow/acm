#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int n,m;
	int c[1000];
	memset(c,0,1000);	
	int big=0;
	int total=0;
	while(scanf("%d %d",&n,&m)==2)
	{
		big=0;
		total=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
			if(c[i]>big)
			{
				big=c[i];
			}
			total=total+c[i];
		}

		while(total>big)
		{
			int middle=(big+total)/2;
			int sum=0;
			int numberb=0;
			for(int i=0;i<n;i++)
			{
				sum=sum+c[i];
				
				if(sum>middle)
				{
					numberb++;
					sum=c[i];
				}
				
				else if(sum==middle)
				{
					numberb++;
					sum=0;
				}
			}
			
			if(sum>0)
			{
				numberb++;
			}
			
			if(numberb>m)
			{
				big=middle+1;
			}
			
			else
			{
				total=middle;
			}
		}
		
		printf("%d\n",big);
		
}
		

} 
