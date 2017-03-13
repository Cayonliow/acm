#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	char sss[1000005];
	while(scanf("%s",sss)!=EOF&&sss[0]!='.')
	{
		int count[1000005]={0};
		count[0]=-1;
		int a=-1;
		for(int i=1;sss[i];i++)
		{
			while(a>=0 && sss[a+1]!=sss[i])
			{
				a=count[a];
			}
			
			if(sss[a+1]==sss[i])
			{
				a++;
			}
			
			count[i]=a;
		}
		
		int length=strlen(sss)-count[strlen(sss)-1]-1;
		
		printf("%d\n",(strlen(sss)%length)==0?strlen(sss)/length:1);
		
	}
}
