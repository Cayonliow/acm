#include<iostream>
#include<cstdio>

using namespace std;

int m,n;
int M[110],N[110]={0};
int l[110][110]={0};
	
int LCS()
{
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0)
			{
				l[i][j]=0;
			}
			
			else if(M[i-1]==N[j-1])
			{
				l[i][j]=l[i-1][j-1]+1;
			}
			
			else
			{
				l[i][j]=max(l[i-1][j],l[i][j-1]);
			}
		}
	}
	
	return l[m][n];
}
	
int main()
{
	
	int count=1;
	
	while((scanf("%d %d",&m,&n)==2)&&(m!=0&&n!=0))
	{
		for(int i=0;i<m;i++)
		{
			scanf("%d",&M[i]);
		}
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&N[i]);
		}
		
		printf("Twin Towers #%d\n",count++);
		printf("Number of Tiles : %d\n\n",LCS());
	}
}
