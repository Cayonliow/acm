#include<iostream>
#include<cstdio>

using namespace std;

long long int X,Y;

int GCD(int a,int b)
{
	if(b==0)
	{
		X=1;
		Y=0;
		return a;
	}
	
	else
	{
		int gcd=GCD(b,a%b);
		int temp=X;
		X=Y;
		Y=temp-(a/b)*Y;
		return gcd;	
	}
	
	
	
	
	
	
	
}


int main()
{
	long long int a,b;
	while(scanf("%lld %lld",&a,&b)==2)
	{
		
		printf("%d %d %d\n",X,Y,GCD(a,b));

	}

	return 0;

 } 
