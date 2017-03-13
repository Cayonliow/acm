#include<cstdio>
#include<iostream>
using namespace std;

void insertionsort(int survive[])
{
	for(int i=2;i<4;i++)
	{
		int temp=survive[i];
		for(int j=i-1;j>=0;j--)
		{
			if(survive[j]>temp)
				{
					survive[j+1]=survive[j];
					survive[j]=temp;
				}
			else
				break;
		}
	}
}

int main()
{
	int number,salary;
	int survive[4];
	while(scanf("%d",&number)==1)
	{
		for(int i=0;i<number;i++)
		{
			for(int j=1;j<=3;j++)
				scanf("%d",&survive[j]);

		insertionsort(survive);
					//for(int j=1;j<=3;j++)
				//printf("%d ",survive[j]);
		printf("Case %d: %d\n",i+1,survive[2]);
		
		}

	}

	return 0;
}

