#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	int number;
	int a,b;
	float length;
	while(cin>>number)
	{
		for(int i=1;i<=number;i++)
		{
			cin>>a>>b;
			//length=2*(a+b-2);
			//length=(2*a)+(2*b)-4; 
			length=a*b;
			if(((a%2)==1)&&((b%2)==1))
			length=length-1+sqrt(2.0);	
			cout<<"Scenario #"<<i<<": "<<endl;
			cout<<fixed<<setprecision(2)<<length<<endl;
			cout<<endl;
		}
		
	}
	
	
	return 0;
 } 
