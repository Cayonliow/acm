#include<iostream>
#include<cstdio>
using namespace std;

void change(int a,int b)
{
	int change;
	change=a;
	a=b;
	b=change;
}

int main()
{
	 long long int a,b;
	//int c[100000]={0};
	long long int count=1;
	long long int length=1;
	long long int number;
	long long c;
	long long aa,bb;
	
	while(scanf("%lld %lld",&a,&b)==2)
	{
		aa=a;
		bb=b;
		c=1;
		if(aa>bb)
		{
			int change;
			change=aa;
			aa=bb;
			bb=change;
		}
		
		//printf("%lld,%lld",aa,bb);return 0;
		for(int h=aa;h<=bb;h++)
		{
			int i=h;	
			
			while(1)
			{	
				if(i==1)
				{
				//count++;
					if(c<count)
					{
						c=count;
					}
					
					count=1;
					break;
			 	}
				 if(i%2==0)
				{
					i=i/2;
					count++;
				}		
					
				 else if(i%2==1)
				{
					i=3*i+1;
					count++;
				}
			
				
			}        
		}
		
		
		printf("%lld %lld %lld\n",a,b,c);

	}
	return 0;
}
