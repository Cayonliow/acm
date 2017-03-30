#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	
	long long int combination[220][220];
	memset(combination,0,sizeof(combination));
		
	for(int i=0;i<=200;i++)
	{
		combination[i][0]=1;
	}
	
	for(int i=1;i<=200;i++)
	{
		for(int j=1;j<=i;j++)
		{
			combination[i][j]=(combination[i-1][j-1]+combination[i-1][j])%1000000;
		}
	}
	
	int N,K;
	while(scanf("%d %d",&N,&K)==2&&N&&K)
	{
		//C(n+k-1,k),combination
		/*long long a=1;
		for(int i=N+K-1;i>=N;i--)
			a=a*i;
		printf("a=%lld\n",a);
	
			
		long long b=1;
		for(int i=K;i>=1;i--)
			b=b*i;
		printf("b=%lld\n",b);
		
		printf("%lld\n",a/b);*/
		

		
		printf("%d\n",combination[N+K-1][K-1]);
		
		
	}
}
