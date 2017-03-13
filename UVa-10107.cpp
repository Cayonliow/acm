#include<iostream>
#include<cstdio>

using namespace std;

void insertionsort(int number,long long int array[])
{
	for(int i=1;i<=number;i++)
	{
		int temp=array[i];
		for(int j=i-1;j>=0;j--)
		{
			if(array[j]>temp)
			{
				array[j+1]=array[j];
				array[j]=temp;
			}
				
			else
				break;
		}
	}
}

int main()
{
	long long int array[20000]={0};
	int i=0;
	while(scanf("%lld",&array[i])!=EOF)
	{
		insertionsort(i,array);

		if(i%2==0&&i!=0)
		{
			printf("%lld\n",array[i/2]);
		}
		
		if(i%2==1&&i!=1)
		{
			printf("%lld\n",(array[i/2]+array[(i/2)+1])/2);
		}
		
		if(i==0)
		{
			printf("%lld\n",array[0]);
		}
		
		if(i==1)
		{
			printf("%lld\n",(array[0]+array[1])/2);
		}
		i++;
	}

	return 0;	
} 


/*
#include<iostream>
#include<cstdio>

using namespace std;

void insertionsort(int number,long long int array[])
{
	for(int i=1;i<=number;i++)
	{
		int temp=array[i];
		for(int j=i-1;j>=0;j--)
		{
			if(array[j]>temp)
			{
				array[j+1]=array[j];
				array[j]=temp;
			}
				
			else
				break;
		}
	}
}

void Merge(long long int list[], int low, int high)
{
	//printf("rr");
	int combined[500000],i,j;
	int k=-1;
	int mid=(low+high)/2;
//printf("%d",k);
	
	for(i=low,j=mid+1;i<=mid||j<=high; )
	{
		if(i>mid)
		{
			combined[++k]=list[j++];
			//change++;
		}
			
		else if(j>high)
		{
			combined[++k]=list[i++];
			//change++;
		}
			
		else if(list[i]>=list[j])
		{
			combined[++k]=list[j++];
			//change++;
		}
			
		else
		{
			combined[++k]=list[i++];
			//change++;
		}
		
	}
	
	k=0;
	for(i=low;i<=high;i++)
		list[i]=combined[k++];
		//change++;
}

void MergeSort(long long int list[], int low, int high)
{
	if(high>low)
	{
		MergeSort(list,low,(low+high)/2);
		MergeSort(list,((low+high)/2)+1,high);
	}	
		
		Merge(list,low,high);//printf("rr");
}
int main()
{
	long long int array[20000]={0};
	int i=0;
        int a;
	while(scanf("%lld",&array[i]))
	{
		insertionsort(i,array);
	
		if(i%2==0&&i!=0)
		{
			a=i/2;
                        printf("%lld\n",array[a]);
		}
		
		if(i%2==1&&i!=1)
		{
			a=(array[i/2]+array[(i/2)+1])/2;
                        printf("%lld\n",a);
		}
		
		if(i==0)
		{
			printf("%lld\n",array[0]);
		}
		
		if(i==1)
		{
			a=(array[0]+array[1])/2; 
                        printf("%lld\n",a);
		}
		i++;
	}

	return 0;	
} */
