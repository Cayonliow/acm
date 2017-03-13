#include<iostream>
#include<cstdio>
const int mmax=1000005;

using namespace std;

int main()
{
	int length;
	char sss[mmax];
	int Case=1;
	//printf("y");
	while(scanf("%d",&length)&&length!=0)
	{
		//getline(cin,sss);
		scanf("%s",sss);
		int rrr[mmax];
		rrr[0]=-1;
		int a=0;
		int b=-1;
		while(a<length)
		{
			if(b==-1||sss[a]==sss[b])
			{
				a++;
				b++;
				rrr[a]=b;
			}
			
			else
			{
				b=rrr[b];
			}
		}
		
		printf("Test case #%d\n",Case);
		Case++;
		
		for(int i=2;i<=length;i++)
		{
			if(rrr[i]!=0 && i%(i-rrr[i])==0)
			{
				printf("%d %d\n",i,i/(i-rrr[i]));
			}
		}
		
		printf("\n");
		
	}
		
} 
