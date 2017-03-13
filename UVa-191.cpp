#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct COOR 
{
    double x,y;
};

COOR p1,p2;

double a,b;

bool Test_rectangles(COOR t)
{
    if(	   t.x>p1.x-0.00001 
		&& t.x<p2.x+0.00001 
		&& t.y<p2.y+0.00001 
		&& t.y>p1.y-0.0001)
		 
        return true;
        
    else
	{
		return false;
	} 
}

void get_polynominal(COOR m,COOR n)
{
    a=(m.y-n.y)/(m.x-n.x);
    b=m.y-(a*m.x);
}


int main()
{
    int N;
    double u;
    scanf("%d",&N);
    COOR line_point1,line_point2,temp;
    while(N--)
	{
       	bool tag = false;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&line_point1.x,
												&line_point1.y,
												&line_point2.x,
												&line_point2.y,
												&p1.x,
												&p1.y,
												&p2.x,
												&p2.y);
        if(p1.x>p2.x)
		{
			swap(p1.x,p2.x);
		}   
        
		if(p1.y>p2.y)
		{
			swap(p1.y,p2.y);
		}   

        if(line_point1.x==line_point2.x)
		{
            if(line_point1.y>line_point2.y)
			{
				swap(line_point1.y,line_point2.y);	
			} 
            for(double i=line_point1.y;i<=line_point2.y+0.0001;i+=0.003)
			{
                temp.x=line_point1.x;
                temp.y=i;
                
				if(Test_rectangles(temp))
				{
                    tag=true;
                    printf("T\n");
                    break;
                }
            }
            
			if(!tag)
			{
				printf("F\n");
			} 
			
            continue;
        }

        if(line_point1.x>line_point2.x) 
		{
            temp=line_point1;
            line_point1=line_point2;
            line_point2=temp;
        }

        get_polynominal(line_point1,line_point2);

        for(double i=line_point1.x;i<=line_point2.x+0.0001;i+=0.05)
		{
            temp.x=i;
            temp.y=a*i+b;
            if(Test_rectangles(temp))
			{
                tag=true;
                printf("T\n");
                break;
            }
        }

        if(!tag)
		{
		 	printf("F\n");
		} 
    }
}
