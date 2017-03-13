#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define MAX 1000000

bool isprime[MAX];

void SIEVE()
{
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	for(int i=2;i<=sqrt(MAX);++i)
	{
		if(isprime[i])
		{
			for(int j=i+i;j<MAX;j+=i)
			{
				isprime[j]=false;
			}
		}
	}
}

using namespace std;



int main()
{
	SIEVE();
	long long int number;
	
	while(cin>>number)
	{	
		if(number<0)return 0;
		int mark=0;
		long long int y=0;
		while(number!=1)
		{
			if(isprime[y] == true)
			{
				if (number % y == 0) 
				{
				number=number / y;
				cout<<"    "<<y<<endl;
				mark=1;
				}
				else
				y++;
			}
			else
			y++;
		
		if(y==1000000&&mark==0)
		{
			cout<<"    "<<number<<endl;break;
		}
		
		
		//long long int rt=number;
		//cout<<y;
	
		if(y==1000000&&number!=1&&mark==1)
		{
			cout<<"    "<<number<<endl;break;
		}
		
	
	}
	cout<<endl;
	
	
	
	
	}
}
