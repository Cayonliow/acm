#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
   
struct Segment  
{  
    double sx, sy, ex, ey;  
}segment[100010];

  
double function(double x_1,double y_1,double x_2,double y_2)  
{  
    return (x_1*y_2)-(x_2*y_1);  
}  
  
bool isIntersect(Segment a,Segment b)  
{  
    if(function(a.ex-a.sx,a.ey-a.sy,b.sx-a.sx,b.sy-a.sy)*   
       function(a.ex-a.sx,a.ey-a.sy,b.ex-a.sx,b.ey-a.sy)<=0 
	   &&  
       function(b.ex-b.sx,b.ey-b.sy,a.sx-b.sx,a.sy-b.sy)*   
       function(b.ex-b.sx,b.ey-b.sy,a.ex-b.sx,a.ey-b.sy)<=0)
	{
	   	return true; 
	} 
        
    return false;  
}  
  
int main()  
{  
    int number;  
    while(scanf("%d",&number)&&number!=0)  
    {  
        memset(segment,0,sizeof(segment));  
        for(int i=0;i<number;i++)  
        {  
            scanf("%lf%lf%lf%lf",&segment[i].sx,   
            					 &segment[i].sy, 
								 &segment[i].ex,
								 &segment[i].ey);  
        }  
          
        printf("Top sticks:");  
        bool one=true;  
        for(int i=0;i<number;i++)  
        {  
            bool flag=true;  
            for(int j=i+1;j<number;j++)  
            {  
                if(isIntersect(segment[i],segment[j]))  
                {  
                    flag=false;  
                    break;  
                }  
            }  
            
			if(flag)  
            {  
                if(!one)  
                {  
                    printf(", %d",i+1);  
                }  
                
				else  
                {  
                    printf(" %d",i+1);  
                    one=false;  
                }  
            }  
        }  
        puts(".");  
    }  
      
    return 0;  
}  
