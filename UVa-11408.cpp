#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int q[5000001];
int prime[5000001];
int add[5000001];
int ans[5000001]; 

void DePrimes()
{
		
	int count=0;	
	
	for(int i=0;i<5000001;++i) 
	{
		q[i]=0;
		add[i]=0;
	}

	for(int i=2;i<5000001;i++) 
	{
		if(q[i]==0) 
		{
			prime[count++]=i;
			add[i]=i;
		}
		
		for(int j=0;j<count&&i*prime[j]<5000001;++j)
		{
			q[i*prime[j]]=1;
			if(!(i%prime[j]))
			{
				add[i*prime[j]]=add[i];
				break;
			}
			else 
				add[i*prime[j]]=add[i]+prime[j];
		}
		ans[i]=ans[i-1]+!q[add[i]];
	}
}




int main()
{

	DePrimes();
	
	int a,b;
	while(scanf("%d",&a)&&a!=0)
	{
		scanf("%d",&b);
		printf("%d\n",ans[b]-ans[a-1]);
	}
}

