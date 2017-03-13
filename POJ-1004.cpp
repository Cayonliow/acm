#include<cstdio>
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	float sum=0;
	float add,average;
	int count=0;
	while(cin>>add)
	{
		count++;
		if(count<=12)
		{
			sum=sum+add;
		}
	if(count==12)
	{
		average=sum/12;
	cout<<"$";
	cout<<setprecision(2)<<fixed<<average<<endl;
	cout.unsetf(ios::fixed);
		count=0;
	sum=0;

	}
	
	}
	
	
	return 0;
}
