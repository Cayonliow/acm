#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int main()
{
	int n;
	priority_queue<long long int,vector<long long int>,greater<long long int> > qq;
	scanf("%d",&n);
	
		//int data1=0;
		long long int data,cost;
		
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&data);
			qq.push(data);
			//data1=data1+data;
		}
		
		
		long long int buffer=0;
	//printf("cost1=%d\n",cost);
		for(int i=0;i<n-1;i++)
		{
			cost=qq.top();
			qq.pop();
			cost=cost+qq.top();
			qq.pop();
			qq.push(cost);
			buffer=buffer+cost;
			//qq.pop();
			//printf("%lld\n",cost);
		}
	
	printf("%lld\n",buffer);
	
	
	
}
