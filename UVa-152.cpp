#include <cstdio>  
#include <cmath>  
#include <cstring>  
#include <iostream>  
using namespace std;  
  
int x[5100], y[5100], z[5100], d[11];  
  
int Distance(int a, int b) 
{  
    int t_X=x[a]-x[b]; 
	int t_Y=y[a]-y[b]; 
	int t_Z=z[a]-z[b];  
    
	return sqrt(pow(t_X,2)+pow(t_Y,2)+pow(t_Z,2));  
}  
  
int main() 
{  
    int count=0;  
    while (scanf("%d%d%d", &x[count], &y[count], &z[count]) && (x[count] || y[count] || z[count])) 
	{  
        count++;  
    }  
   
    memset (d, 0, sizeof(d));  
    for (int i=0;i<count;i++) 
	{  
        int Min=1000;  
        for(int j=0;j<count;j++) 
		{  
            if (i==j)
			{
				continue;
			}   
            int temp=Distance(i,j);  
            
			if (temp<Min) 
			{  
                Min=temp;  
            }  
        }  
        if(Min>=0&&Min<=9)  
        {
        	d[Min]++;
		}   
		 
    }  
    
    for (int i=0;i<10;i++)
	{
		printf("%4d", d[i]); 
	}  
         
    printf("\n");  
    return 0;  
}  
