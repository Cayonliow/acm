#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;



int findperiod(char* s)
{
	//if(s.length()==1)return 1;
	if(strlen(s)==1)
	{
		return 1;	
	} 
	int a=0,b=1;
	//while(b!=s.length())
	while(s[b]!=NULL)
	{
		if(s[a]==s[b])
		{
			++a;
			++b;
		}
		
		else
		{
			++b;
		}
	}
	//return (s.length()%(b-a)==0)?b-a:s.length();
	return (strlen(s)%(b-a)==0)?b-a:strlen(s);
}

int main()
{
	int Case;
	string s;
	//while(scanf("%d%*c",&Case))
	scanf("%d ",&Case);
//	{
		while(Case--)
		//for(int i=0;i<=Case;i++)
		{
			char s[256];
			scanf("%s",s);
			//getline(cin,s);
			//printf("%d\n",findperiod(s));
			printf("%d\n",findperiod(s));
			if(Case>0)
			{
				putchar('\n');
			}
		
		}
	//}
	return 0;
}
