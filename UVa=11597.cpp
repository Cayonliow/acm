#include<iostream>

using namespace std;

int main()
{
	long long int N=0;
	int count=0;
	while(scanf("%lld",&N)==1 && N)
	{
		count++;
		printf("Case %d: %lld\n",count,N/2);
	}
}
