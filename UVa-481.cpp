#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int arr[100010];
	memset(arr,0,100010);
	int number=0;
	int tmp[100010]; //
	memset(tmp,0,100010);
	int pos[100010];//
	memset(pos,0,100010);
	int ans[100010];
	memset(ans,0,100010);
	
	while(scanf("%d",&arr[number])!=EOF)
	{
		number++;//
	}
	//printf("yyyyy");
	
	int m=1;//length of tmp
	tmp[0]=arr[0];
	pos[0]=0;
	for(int i=1;i<number;i++)
	{
		int t=lower_bound(tmp,tmp+number,arr[i])-tmp;
		tmp[t]=arr[i];
		pos[i]=t;
		m=t+1>m?t+1:m;
	}
	
	printf("%d\n-\n",m--);
	
	int n=0;
	for(int i=number-1;i>=0;--i)
	{
		if(pos[i]==m)
		{
			ans[n++]=arr[i];
			--m;
		}
		
		for(int i=n-1;i>=0;--i)
		{
			printf("%d\n",ans[i]);
		}
	}
	
	return 0;
	

	
}


