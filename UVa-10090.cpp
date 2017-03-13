#include<iostream>
#include<cstdio>
#include <cstring>
#include <cmath>
using namespace std;

 long long int extendGCD( long long int a,  long long int b,  long long int &x,  long long int &y) {
    if (b==0) 
	{
		x=1;
		y=0; 
		return a;
	}
	
     long long int tmp=extendGCD(b,a%b,y,x);
    y=y-a/b*x;
    return tmp;
}

 long long int n, c1, c2, n1, n2;

int main() {
	
	while (scanf("%lld", &n)&&n) {
    	scanf("%lld%lld%lld%lld", &c1, &n1, &c2, &n2);
    	                        
		long long int x, y,d,Down,Up;
    	
    	d=extendGCD(n1,n2,x,y);
    	
		Down=ceil(1.0*-n*x/n2);
    	Up=floor(1.0*n*y/n1);
    	
		if(Down>Up||n%d) 
		{
        	printf("failed\n");
        	continue;
    	}
    	
		x=n*x/d;
    	y=n*y/d;
	
		if(c1*n2<c2*n1) 
		{
        	x=x+n2/d*Up;
        	y=y-n1/d*Up;
    	}
    	
		else 
		{
        	x=x+n2/d*Down;
        	y=y-n1/d*Down;
    	}
    	printf("%d %d\n",x,y);
    }

}
