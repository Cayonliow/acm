#include <cstdio>
#include <string>
#include <map>
#include <queue>
using namespace std;
int main()
{
    int Case = 1; 
	int N, M;
	map<string, int> Mapping;
	char A[100], B[100];
    double rate;
	
    while(scanf("%d",&N)==1 && N!=0) 
	{
        double Rate[35][35]={0};

        for(int i=0;i<N;i++)
        {
        	Rate[i][i]=1;
		}
            
        for (int i=0;i<N;i++)
		{
            scanf("%s",A);
            Mapping[A]=i;
        }
        
		scanf("%d", &M);
		
        for (int i=0;i<M;i++)
		{
            scanf("%s %lf %s",A,&rate,B);
            Rate[Mapping[A]][Mapping[B]]=rate;
        }

        for (int k=0;k<N;k++)
        {
        	for (int i=0;i<N;i++)
        	{
        		for (int j=0;j<N;j++)
        		{
        			if (Rate[i][k]*Rate[k][j]>Rate[i][j])
        			{
        				Rate[i][j]=Rate[i][k]*Rate[k][j];
					}   
				}
			}
 		}
            
        bool yes = false;
        
        for (int i=0;i<N;i++)
        {
        	if (Rate[i][i]>1)
        	{
        		yes = true;
			} 
		}
            
        printf("Case %d: ",Case++);
        
		if(yes==true)
		{
			puts("Yes");
		} 
        
		else
		{
        	puts("No");
		}
    }
}
