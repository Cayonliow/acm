#include<iostream>
#include<cstdio>
using namespace std;

int array[30][30]={0};

void search(int i,int j)
{
	
		array[i][j]=0;
		
		if(array[i-1][j-1]==1)
		{
			search(i-1,j-1);
		}
		
		if(array[i][j-1]==1)
		{
			search(i,j-1);
		}
		
		if(array[i+1][j-1]==1)
		{
			search(i+1,j-1);
		}
		
		if(array[i+1][j]==1)
		{
			search(i+1,j);
		}
		
		if(array[i+1][j+1]==1)
		{
			search(i+1,j+1);
		}
		
		if(array[i][j+1]==1)
		{
			search(i,j+1);
		}
		
		if(array[i-1][j+1]==1)
		{
			search(i-1,j+1);
		}
		
		if(array[i-1][j]==1)
		{
			search(i-1,j);
		}
		
		//return 1;
	//}	
}

int main()
{
	int number;
	int times=0;
	int count;
	while((scanf("%d",&number))!=EOF)
	{
		count=0;
		times++;
		for(int i=1;i<=number;i++)
		{
			for(int j=1;j<=number;j++)
			{
				scanf("%1d",&array[i][j]);
			}
		}
		
		for(int i=1;i<=number;i++)
		{
			for(int j=1;j<=number;j++)
			{
				if(array[i][j]==1)
				{
				search(i,j);
				count++;
				}
			}
		}
		
		printf("Image number %d contains %d war eagles.\n",times,count);

	}
	//printf("\n");
	return 0;
}
