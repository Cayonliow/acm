#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	map<string,string> dic;
	map<string,string>::iterator it;
	string s1,s2,findd;
	char word[30],s1ass[25],s2ass[25];
	while(gets(word)&&word[0]!='\0')
	{
		sscanf(word,"%s %s",s1ass,s2ass);
		s1.assign(s1ass);
		s2.assign(s2ass);
		
		dic[s2]=s1;
	}	
		
	
	//cout<<"FF";
	char space[30];
	//cin>>space;
	while(gets(space))
	{
		findd.assign(space);
		//cout<<findd<<"this"<<endl;
		if(dic[findd].length()==0)
		{
			cout<<"eh"<<endl;
		}
		else
		{
			cout<<dic[findd]<<endl;
		}
		
		
		
		
		
		
		
		/*findd.assign(space);
		int mark=0;
		it=dic.find(findd);
		if(it!=dic.end())
		{
			cout<<it->second<<endl;
		}
		
		else
		{
			cout<<"eh"<<endl;
		}
		*/
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		/*for(it=dic.begin();it!=dic.end();++it)
		{
			if(find==it->second)
			{
				
				//printf("%s",it->first);
				cout<<it->first<<endl;
				mark=1;
			}
		}
			if(mark==0)
			{
				cout<<"eh"<<endl;
			}
		*/
	}
} 
