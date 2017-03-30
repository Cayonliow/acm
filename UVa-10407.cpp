#include<cstdio>
#include<cstdlib>

int gcd(int a, int b)
{
	if(a == 0)	return b;
	
	return gcd(b % a, a);
 } 

int main()
{
	int arr[1005];
	int temp, temp2;
	int  n, g;
	while (scanf("%d", &temp), temp)
	{
		int count = 0;
		while(scanf("%d", &temp2) && temp2)
		{
			arr[count] = temp2 - temp;
			temp = temp2;
			count++;
		}

		int count_zero = 0;
		for (int i = 0; i<count; ++i)
		{
			if(arr[i]==0)
			count_zero++;
		}

			g = arr[count_zero];
			
		for(int i = count_zero; i < count; i++)
		{
			if (arr[i]!=0)
			{
				g = gcd(arr[i], g);
			 } 
			
		}
			
		printf("%d\n", abs(g));
	}
	return 0;
}
