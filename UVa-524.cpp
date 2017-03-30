#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
int N;
int arr[18];
int node[18];

int Is_prime(int n)     
{
    if(n<2)
        return false;
        
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

void DFS(int number)
{
    if(number==N&&Is_prime(arr[1]+arr[N]))  
    {
        for(int i=1;i<N;i++)
        {
        	printf("%d ",arr[i]);
		}
        printf("%d\n",arr[N]);	
	}
    else
    {
        for(int i=2;i<=N;i++)
        {
            if(!node[i]&&Is_prime(i+arr[number]))   
            {
                arr[number+1]=i;
                node[i]=1;              
                
				DFS(number+1);
                node[i]=0;            
            }
        }
    }
}
int main()
{
    int Case=0;
    while(scanf("%d",&N)!=EOF&&N)
    {
        memset(node,0,sizeof(node));
        arr[1]=1;
		if(Case)	
		{
			printf("\n");
		}
        printf("Case %d:\n",++Case);
        DFS(1);
    }
    return 0;
}
