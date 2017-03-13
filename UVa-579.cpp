#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int H,M;
	float countH,countM,angle;
	while(scanf("%d:%d",&H,&M))
	{
		if(H==0&&M==0)
			return 0;
		
		countM=M*360/60;
		countH=(H*360/12)+countM*5/60;

		angle=countH-countM;
		
		if(angle>180)
			angle=360-angle;	
		
		if(angle<0)
		{
			angle=angle*-1;
			if(angle>180)
				angle=360-angle;
		}

		printf("%.3f\n",angle);
	}
	
	
return 0;	
} 
