#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	
	long long int m;
	int n;
	int array[100000]={0};
	int answer[10000]={0};
	string s1;
	long long int t;
	
	while(cin>>m) 
	{
		for(int i=0;i<m;i++)
		{
			cin>>array[i];
		}
		
		sort(array,array+m);
		
		cin>>s1;
		
		if(s1=="###")
		{
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cin>>t;
				answer[i]=array[t-1];
			}
		}
		
		for(int i=0;i<n;i++)
		{
			cout<<answer[i]<<endl;
		}
	}


	return 0;
		
} 
