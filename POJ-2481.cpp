#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int A[1000001];
int C[1000001];

struct c
{
	int i,L,R;
} F[1000001];

int compare(c a, c b)
{
	if(a.R==b.R)
	{
		return a.L<b.L;
	}
	
	else
	{
		return a.R>b.R;
	}
}

int readin(int n)
{
	int s=0;
	/*while(n>0)
	{
		s=s+C[n];
		n=n-(n&-n);
	}*/
	
	for(;n>0;n=n-((n&-n)))
	{
		s=s+C[n];
	}
	return s;
}

void update(int n)
{
	/*while(n<=1000001)
	{
		C[n]++;
		n=n+(n&(-n));
	}*/
	for(;n<=1000001;n=n+((n&-n)))
	{
		C[n]++;
	}
	 
}

int main()
{
	int number;
	while(scanf("%d",&number)==1 &&number!=0)
	{
		memset(A,0,sizeof(A));
		memset(C,0,sizeof(C));
		
		for(int i=1;i<=number;++i)
		{
			scanf("%d %d",&F[i].L,&F[i].R);
		//}
		
		//for(int i=0;i<number;++i)
		//{
			F[i].L++;
			F[i].R++;
			F[i].i=i;
		}
		
		sort(F+1,F+number+1,compare);
		
		int low=-1;
		int high=-1;
		
		for(int i=1;i<=number;++i)
		{
			if(F[i].L==low && F[i].R==high)
			{
				A[F[i].i]=A[F[i-1].i];
			}
		
			else
			{
				low=F[i].L;
				high=F[i].R;
				A[F[i].i]=readin(F[i].L);
			}
		
			update(F[i].L);
		}
	
		for(int i=1;i<number;++i)
		{
			printf("%d ",A[i]);
		}
		printf("%d\n",A[number]);
	
	
	}
}
