#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double  p,q,r,s,t,u;
double search(double low,double high)
{
	
	double middle=(high+low)/2;
	double y=p*exp(-middle)+q*sin(middle)+r*cos(middle)+s*tan(middle)+t*pow(middle,2)+u;
	if(abs(y-0)<pow(10,-12))
	{
		return middle;
	}
	if(y>0)
	{
		search(middle,high);
	}
	
	else if(y<0)
	{
		//printf("tt");
		search(low,middle);	
	}

}
int main()
{
	double y1,y2;
	double x;
	while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF)
	{
		//y=p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x,2)+u;
		y1=p*exp(-0)+q*sin(0)+r*cos(0)+s*tan(0)+t*pow(0,2)+u;
		y2=p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t*pow(1,2)+u;
		if(y1*y2<=0)
		{
			//printf("ww");
			printf("%.4lf\n",search(0,1));
		}
		
		else
		{
			printf("No solution\n");
		}
	
	}



}
