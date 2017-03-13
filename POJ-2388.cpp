#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int odd,median;
	long long int cow[10000]={0};
	
	while(cin>>odd)
	{
		for(int i=0;i<odd;i++)
		{
			cin>>cow[i];
		}
		
		sort(cow,cow+odd);
		
		median=odd/2;
		
		cout<<cow[median]<<endl;
		
	}
	


	return 0;	
} 
