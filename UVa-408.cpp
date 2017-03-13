#include<iostream>
#include<cstdio>

using namespace std;

int gcd(int a,int b)
{
	if(a==0)
	return b;
	return gcd(b%a,a);
}
		

int main()
{
	int step,mod;
	int ans;
	int c;
	while(scanf("%d %d",&step,&mod)==2)
	{
		printf("%10d%10d",step,mod);
		ans=gcd(step,mod);
		if(ans==1)
		{
			printf("    Good Choice\n\n");
		}
		else
		{
			printf("    Bad Choice\n\n");
		}
		

	}
}
