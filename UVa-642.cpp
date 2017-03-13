#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map> 
#include<cstring>
#include<string>

using namespace std;

int main()
{
	string buffer1,buffer2;
	char arrange[100],find[100];
	map<string,string> mapping;
	map<string,string>::iterator it;
	int mark;
	while(cin>>arrange)
	{
		buffer1.assign(arrange);
		if(buffer1=="XXXXXX")break;
		sort(arrange,arrange+strlen(arrange));
		
		mapping[buffer1]=arrange;
		//cout<<mapping[buffer];
	}	
	
	while(cin>>find)
	{
		mark=0;
		buffer2.assign(find);
		if(buffer2=="XXXXXX")break;
		sort(find,find+strlen(find));
		for(it=mapping.begin();it!=mapping.end();++it)
		{
			if(find==mapping[it->first])
			{
				cout<<it->first<<endl;
				mark=1;
			}
		}
		
		if(mark==0)
		{
			cout<<"NOT A VALID WORD"<<endl;
		}
		cout<<"******"<<endl;
	}
} 
