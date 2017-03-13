#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int number;
	int cow[10000]={0};
	long long int sum;
	while(cin>>number)
	{
		for(int i=0;i<number;i++)
		{
			cin>>cow[i];
		}
		sum=0;
		for(int h=0;h<number-1;h++)
		{
			for(int g=h+1;g<number;g++)
			{
				sum=sum+abs(cow[h]-cow[g]);
			}
		}
		
		cout<<sum*2<<endl;
	}
	
	
	
	
	return 0;
	
}
