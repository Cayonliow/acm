#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
 
char  prime[100000000];

int main()
{
 
    for(int i=2;i<=100000000;i++)
		prime[i]=1;     
    
	int k=2;
    for(int m=2;m<=sqrt(100000000);m++)
	{
      for(int j=k*2;j<=100000000;j=j+k)
        prime[j]=0;
    
    k++;
        for(;!prime[k];k++);
	}
    
	               
    long long int input;
	bool flag;
    while(scanf("%lld",&input))
    {
    	if(input%2==1)
     	{
      		if(prime[input-2]==0)
			  	printf("%lld is not the sum of two primes!\n",input);
      		
			else 
				printf("%lld is the sum of 2 and %lld.\n",input,input-2);
      	}
     	
		else 
     	{
      		int m=0;
      		flag=false;
      		for(int i=input/2;i<input;++i)
      		{
				if((prime[(input/2)-m]==1)&&(prime[i]==1)&&(((input/2)-m)!=i))
        		{
         			printf("%llu is the sum of %llu and %llu.\n",input,input-i,i);
         			flag=true;
         			break;
        		}
        		m++;
      		}
      		
			if(!flag)
				printf("%llu is not the sum of two primes!\n",input);
    	} 
    }
}
