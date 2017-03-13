#include<iostream>
#include<cstdio> 
#include<cmath>

using namespace std;

struct COOR
{
    double x,y;
};

struct LINE
{
    double a,b,c;
};
 
LINE getLine(COOR p1,COOR p2)
{
    LINE temp;
    temp.a=p1.y-p2.y;
    temp.b=p2.x-p1.x;
    temp.c=p1.x*p2.y-p2.x*p1.y;
    return temp;
}
 
bool parallel(LINE l1,LINE l2)
{
    return abs(l1.a*l2.b-l2.a*l1.b)<1e-8;
}
 
bool lineEqual(LINE l1,LINE l2)
{
    if(!parallel(l1,l2))
	{
		return false;	
	} 
    
	return (abs(l1.a*l2.c-l2.a*l1.c)<1e-8
		  &&abs(l1.b*l2.c-l2.b*l1.c)<1e-8);
}
 
COOR getIntersect(LINE l1,LINE l2)
{
    COOR tmp;
    tmp.x=(l1.b*l2.c-l2.b*l1.c)/(l1.a*l2.b-l2.a*l1.b);
    tmp.y=(l1.c*l2.a-l2.c*l1.a)/(l1.a*l2.b-l2.a*l1.b);
    return tmp;
}
 
int main(){
    int t;
    COOR point[4];
    LINE l1, l2;

    scanf("%d", &t);
    printf("INTERSECTING LINES OUTPUT\n");
	for(int ttt=0;ttt<t;ttt++)
	{
        for(int i=0;i<4;i++)
        {
        	scanf("%lf%lf",&point[i].x,&point[i].y);
		}
            
        l1=getLine(point[0],point[1]);
        l2=getLine(point[2],point[3]);
        
		if(lineEqual(l1,l2))
		{
            printf("LINE\n");
        }
        
		else if(parallel(l1,l2))
		{
            printf("NONE\n");
        }
        
		else
		{
            COOR ans=getIntersect(l1,l2);
           
            printf("POINT %.2lf %.2lf\n",ans.x,ans.y);
        }   
        
    }
    printf("END OF OUTPUT\n");
    return 0;
}
