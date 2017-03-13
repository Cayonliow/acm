#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	string s1,s2;
	int store1[100]={0};
	int store2[100]={0};
	int match[27]={0};
	
	cin>>s1>>s2;
	
		for(int i=0;i<s1.length();i++)
		{
			store1[s1[i]-'A']++;
		}
		
		for(int i=0;i<s2.length();i++)
		{
			store2[s2[i]-'A']++;	
		}	
		
		sort(store1,store1+27);
		sort(store2,store2+27);
		
		for(int i=0;i<27;i++)
		{
			if(store1[i]!=store2[i])
			{
				cout<<"NO";
				return 0;
			}
			
		}
		
		cout<<"YES";
		
	
}
