#include<iostream>
#include<cstdio>

using namespace std;

int matrix[5][5]={	{0,1,1,0,1},
					{1,0,1,0,1},
					{1,1,0,1,1},
					{0,0,1,0,1},
					{1,1,1,1,0}	};
					
int path[8]={0};

void DFS(int index, int now)
{
	path[index]=now;
	if(index==8)
	{
		for(int i=0;i<9;i++)
		{
			printf("%d",path[i]+1);
		}
		printf("\n");
		return;
	}
	
	
	for(int i=0;i<5;i++)
	{
		if(matrix[now][i]==1)
		{
			matrix[now][i]=0;
			matrix[i][now]=0;
			DFS(index+1,i);
			matrix[now][i]=1;
			matrix[i][now]=1;
		}
	}
}


int main()
{
	DFS(0,0);
	return 0;		
} 
