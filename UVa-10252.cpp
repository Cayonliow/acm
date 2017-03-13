#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>

using namespace std;

int main()
{
	string s1,s2;

	

	while(getline(cin,s1))
	{
		getline(cin,s2);
		
		int counts1[30]={0};
		int counts2[30]={0};
		int countt[30]={0};
		
		for(int i=0;i<s1.length();i++)
		{
			counts1[s1[i]-'a']++;
		}
		
		for(int i=0;i<s2.length();i++)
		{
			counts2[s2[i]-'a']++;
		}
		
		for(int i=0;i<30;i++)
		{
			countt[i]=(counts1[i]<counts2[i])?counts1[i]:counts2[i];
			
			if(countt>0)
			{
				for(int j=0;j<countt[i];j++)
				{
					printf("%c",'a'+i);
				}
			}
		
		
		}
		printf("\n");
		
		
	}











}
