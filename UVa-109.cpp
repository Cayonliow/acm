#include <algorithm>  
#include <iostream>  
#include <cstdlib>  
#include <cstdio>  
#include <cmath>  
  
using namespace std;  
  
typedef struct pnode  
{  
    double x,y,d;  
    pnode(double a,double b)
	{
		x=a;
		y=b;
	}  
    pnode(){};
	  
}point;  

point Po,Pn;  
point P[25][105];  
  
typedef struct snode  
{  
    double x,y,dx,dy;  
    snode( point a, point b ) 
	{
		x = a.x;
		y = a.y;
		dx = b.x-a.x;
		dy = b.y-a.y;
	}  

}segment;  
    
typedef struct cnode  
{  
    int size;  
    double area;  
    int used;  
    cnode(int i,double s)
	{
		size = i;
		area = s;
	}
	cnode(){};   

}convex;  

convex C[25];  
  
bool cmp1(point a,point b)  
{  
    if ( a.x == b.x ) return a.y < b.y;  
    else return a.x < b.x;  
}  
  
double dist( point a, point b )  
{  
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));  
}  
  
double crossproduct( point a, point b, point c )  
{  
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);  
}   
     
bool cmp2(point a,point b)  
{  
    double cp = crossproduct( Po, a, b );  
    if ( cp == 0 ) return a.d < b.d;  
    else return cp > 0;  
}  
  
convex Graham(point *p,int N)  
{  
    sort( p+0, p+N, cmp1 );  
    Po = p[0];  
    for (int i=1;i<N;++ i)
	{
		p[i].d = dist(p[0],p[i]); 
	} 
         
    sort( p+1, p+N, cmp2 );  
      
    int top = N;  
    if ( N > 2 ) 
	{  
        top = 2;  
        for(int i=3;i<N;++ i) 
		{  
            while ( top > 0 && crossproduct( p[top-1], p[top], p[i] ) <= 0 )
			{
				-- top;  
			} 
            p[++ top] = p[i];  
        }  
        p[++ top] = p[0];  
 
        int now = 1;  
        for(int i = 2;i <= top;++ i) 
		{  
            if ( crossproduct( p[now-1], p[now], p[i] ) == 0 )
			{
				p[now] = p[i];
			}   
            else p[++ now] = p[i];  
        }     
        
		top = now;  
    }  
      
    double sum = 0.0;  
    for (int i=2;i<top;++ i) 
    {
    	sum+=crossproduct(p[0],p[i-1],p[i]);  
	}
        
          
    return convex(top, sum*0.5);  
}  
   
bool cross( segment a, segment b )  
{  
    double t1 = a.dy*(b.x-a.x)-a.dx*(b.y-a.y);  
    double t2 = a.dy*(b.x+b.dx-a.x)-a.dx*(b.y+b.dy-a.y);  
    double t3 = b.dy*(a.x-b.x)-b.dx*(a.y-b.y);  
    double t4 = b.dy*(a.x+a.dx-b.x)-b.dx*(a.y+a.dy-b.y);  
    return t1*t2 <= 0 && t3*t4 <= 0;  
}  
  
//???????   
bool pos( point p, segment s )  
{  
    if ( s.dy*(p.x-s.x)-s.dx*(p.y-s.y) == 0 )  
    if ( (s.x-p.x)*(s.x+s.dx-p.x) <= 0 )  
    if ( (s.y-p.y)*(s.y+s.dy-p.y) <= 0 )  
        return 1;  
    return 0;  
}   
  
double temp[4][2] = {501,-1,-1,501,
					 501,501,-1,-1};  
double area( point s, point *p, convex& c )  
{   
    if  ( c.used ) return 0;
	  
    for ( int t = 0 ; t < 4 ; ++ t ) 
	{  
        point   out = point( temp[t][0], temp[t][1] );   
        segment s1  = segment( s, out );  
        int     cp  = 0;  
        for ( int i = 0 ; i < c.size ; ++ i ) 
		{  
            segment s2 = segment( p[i], p[i+1] );  
            if ( pos( s, s2 ) ) 
			{  
                c.used = 1;  
                return c.area;  
            }  
            if ( cross( s1, s2 ) ) cp ++;  
            if ( pos( p[i], s1 ) ) cp --;  
        }  
        if ( cp%2 == 0 ) return 0;  
    }  
    c.used = 1;  
    return c.area;  
}  
  
int main()  
{  
    int n,count = 0;  
    while ( scanf("%d",&n) && n != -1 ) 
	{  
        for ( int i = 0 ; i < n ; ++ i ) 
		{
			scanf("%lf%lf",&P[count][i].x,&P[count][i].y); 
		} 
 
        C[count] = Graham( P[count], n );  
        C[count ++].used = 0;  
    }  
      
    double x,y,sum = 0.0;  
    while ( scanf("%lf%lf",&x,&y) != EOF )
	{
		for ( int i = 0 ; i < count ; ++ i )
		{
			sum += area( point( x, y ), P[i], C[i] );
	 	} 
	}  
            
    printf("%.2lf\n",sum);  
    return 0;  
}  
