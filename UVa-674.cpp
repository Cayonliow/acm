#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

int value[5]={1,5,10,25,50};

void table(int exist[])
{
		for(int i=0;i<5;i++)
	{
		for(int j=value[i];j<=7489;j++)
		{
	
			if(exist[j-value[i]]>0)
				exist[j]+=exist[j-value[i]];
		}
	}


}

int main()
{
	int number;
	int exist[7500];
	memset(exist,0,sizeof(exist));
	exist[0]=1;
	table(exist);
	while(scanf("%d",&number)==1)
	{
	
		printf("%d\n",exist[number]);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
