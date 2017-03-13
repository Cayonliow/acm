#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	char city1[200],city2[200];
	int count=1;
	while(gets(city1) && city1[0]!='#')
	{
		gets(city2);
		int LCS[200][200]={0};
		
		for(int i=1;i<=strlen(city1);i++)
		{
			for(int j=1;j<=strlen(city2);j++)
			{
				if(city1[i-1]==city2[j-1])
				{
					LCS[i][j]=LCS[i-1][j-1]+1;
				}
				
				else
				{
					if(LCS[i-1][j]>LCS[i][j-1])
					{
						LCS[i][j]=LCS[i-1][j];
					}
					
					else
					{
						LCS[i][j]=LCS[i][j-1];
					}
				}
				
			}
		}
	
		printf("Case #%d: you can visit at most %d cities.\n",count++,LCS[strlen(city1)][strlen(city2)]);
	
	}
}
